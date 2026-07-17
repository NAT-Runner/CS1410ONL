/*
 * PLAN
 * ----
 * Data design:
 * The program uses two structures: Item and Stack.
 * Each Item stores one double value and a pointer named next.
 * The next pointer points to the Item underneath it in the stack.
 * The Stack structure stores a pointer named top, which points to the
 * Item currently at the top of the stack. If the stack is empty, top is
 * nullptr. The Stack also stores size, which tracks how many Items are
 * currently in the stack.
 *
 * push():
 * To push a value, create a new Item using new.
 * Store the number in the new Item's value field.
 * Set the new Item's next pointer to the current stack top.
 * Move stack->top so it points to the new Item.
 * Increase stack->size by 1.
 *
 * pop():
 * If the stack is empty, do nothing.
 * Otherwise, save the current top Item in a temporary pointer.
 * Move stack->top to the Item underneath the current top.
 * Delete the old top Item to free heap memory.
 * Decrease stack->size by 1.
 *
 * Edge cases:
 * If pop() is called on an empty stack, it should not crash and should
 * simply do nothing.
 * If top() is called on an empty stack, it should return HUGE_VAL.
 * If print() is called on an empty stack, it should print the divider
 * lines and show 0 ITEMS.
 */

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Each Item represents one value in the stack.
struct Item {
    double value;  // The actual number stored in this stack item
    Item* next;    // Pointer to the item below this one
};

// Stack keeps track of the top item and the number of items.
struct Stack {
    Item* top;  // Points to the top item in the stack
    int size;   // Counts how many items are currently in the stack
};

// Adds a new number to the top of the stack.
void push(Stack* stack, double num) {
    // Create a new Item on the heap.
    Item* newItem = new Item;

    // Store the value inside the new Item.
    newItem->value = num;

    // The new Item should point to the old top item.
    newItem->next = stack->top;

    // The new Item now becomes the top of the stack.
    stack->top = newItem;

    // Increase the stack size because one item was added.
    stack->size++;
}

// Returns the value at the top of the stack.
double top(Stack* stack) {
    // If the stack is empty, return HUGE_VAL.
    if (stack->top == nullptr) {
        return HUGE_VAL;
    }

    // Otherwise, return the value stored in the top item.
    return stack->top->value;
}

// Removes the top item from the stack.
void pop(Stack* stack) {
    // If the stack is empty, there is nothing to remove.
    if (stack->top == nullptr) {
        return;
    }

    // Save the current top item before moving the top pointer.
    Item* oldTop = stack->top;

    // Move the top pointer to the item underneath the old top.
    stack->top = stack->top->next;

    // Delete the old top item to free the memory.
    delete oldTop;

    // Decrease the stack size because one item was removed.
    stack->size--;
}

// Prints the stack from top to bottom.
void print(Stack* stack) {
    // Print the top divider line.
    cout << setw(15) << "----------" << endl;

    // Start at the top of the stack.
    Item* current = stack->top;

    // Walk through the stack until reaching nullptr.
    while (current != nullptr) {
        // Print the value right-aligned.
        cout << setw(15) << current->value;

        // Mark only the top item.
        if (current == stack->top) {
            cout << " < TOP";
        }

        cout << endl;

        // Move to the next item below.
        current = current->next;
    }

    // Print the bottom divider line.
    cout << setw(15) << "----------" << endl;

    // Print the total number of items.
    cout << setw(15) << stack->size << " ITEMS" << endl;
}

int main() {
    // Create an empty stack.
    Stack stack;

    // An empty stack should start with top as nullptr and size as 0.
    stack.top = nullptr;
    stack.size = 0;

    // Push at least 5 values onto the stack.
    // The last value pushed will become the top item.
    push(&stack, 20.5);
    push(&stack, 60.004);
    push(&stack, 10.08);
    push(&stack, 40.3);
    push(&stack, -160.93);

    // Print the full stack.
    cout << "Full stack:" << endl;
    print(&stack);
    cout << endl;

    // Remove one item from the top.
    pop(&stack);

    // Print the stack after one pop.
    cout << "After one pop:" << endl;
    print(&stack);
    cout << endl;

    // Pop until the stack is empty.
    while (stack.size > 0) {
        pop(&stack);
    }

    // Print the empty stack to test the empty state.
    cout << "Empty stack:" << endl;
    print(&stack);
    cout << endl;

    // Push 3 more values after the stack was emptied.
    push(&stack, 100.1);
    push(&stack, 200.2);
    push(&stack, 300.3);

    // Print the final stack.
    cout << "Final stack:" << endl;
    print(&stack);
    cout << endl;

    // Clean up any remaining items before the program ends.
    while (stack.size > 0) {
        pop(&stack);
    }

    return 0;
}