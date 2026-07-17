#ifndef STRING_MAKER_H
#define STRING_MAKER_H

/*
 * PLAN
 * ----
 * Member functions vs. friend functions:
 *   I will make *, +, -, ==, and != member functions because a
 *   StringMaker object appears on the left side when they are used.
 *
 *   I will make >> and << friend functions. The left side of >>
 *   is a string, and the left side of << is an output stream such
 *   as cout. Neither one is a StringMaker object. Making these
 *   functions friends lets them access the private buffer.
 *
 * Return types:
 *   The *, +, and - operators return StringMaker& because each one
 *   changes the current object and returns that same object.
 *   The comparison operators return bool because their result is
 *   either true or false. The >> operator returns void, and the <<
 *   operator returns the output stream.
 *
 * Chaining:
 *   Returning *this by reference returns the same object that was
 *   changed. This lets the next operator continue working with that
 *   object, such as (sb * 3) * 2.
 */

#include <iostream>
#include <string>

class StringMaker {
private:
    std::string buffer;

public:
    // Constructors
    StringMaker();
    StringMaker(const std::string& startingString);

    // Basic StringMaker functions
    void clear();
    unsigned int size() const;
    const std::string& str() const;

    // Operators that change the StringMaker object
    StringMaker& operator*(unsigned int numberOfCopies);
    StringMaker& operator+(const std::string& addedString);
    StringMaker& operator-(unsigned int charactersToRemove);

    // Operators that compare two StringMaker objects
    bool operator==(const StringMaker& other) const;
    bool operator!=(const StringMaker& other) const;

    // Friend operators
    friend void operator>>(const std::string& addedString,
                           StringMaker& sb);

    friend std::ostream& operator<<(std::ostream& output,
                                    StringMaker& sb);

    ~StringMaker() = default;
};

#endif