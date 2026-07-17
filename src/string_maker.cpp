#include "string_maker.h"

// Create a StringMaker with an empty buffer.
StringMaker::StringMaker()
    : buffer("") {
}

// Create a StringMaker with a starting string.
StringMaker::StringMaker(const std::string& startingString)
    : buffer(startingString) {
}

// Remove everything currently stored in the buffer.
void StringMaker::clear() {
    buffer.clear();
}

// Return the number of characters in the buffer.
unsigned int StringMaker::size() const {
    return static_cast<unsigned int>(buffer.size());
}

// Return the string stored in the buffer.
const std::string& StringMaker::str() const {
    return buffer;
}

// Repeat the current buffer the requested number of times.
StringMaker& StringMaker::operator*(unsigned int numberOfCopies) {
    if (numberOfCopies == 0) {
        buffer.clear();
    }
    else if (numberOfCopies > 1) {
        std::string startingText = buffer;

        for (unsigned int copy = 1; copy < numberOfCopies; copy++) {
            buffer += startingText;
        }
    }

    return *this;
}

// Add a string to the end of the buffer.
StringMaker& StringMaker::operator+(
    const std::string& addedString) {

    buffer += addedString;
    return *this;
}

// Remove characters from the end of the buffer.
StringMaker& StringMaker::operator-(
    unsigned int charactersToRemove) {

    if (charactersToRemove >= buffer.size()) {
        buffer.clear();
    }
    else {
        unsigned int newSize =
            static_cast<unsigned int>(buffer.size()) -
            charactersToRemove;

        buffer.erase(newSize);
    }

    return *this;
}

// Check whether two StringMaker objects contain the same text.
bool StringMaker::operator==(const StringMaker& other) const {
    return buffer == other.buffer;
}

// Check whether two StringMaker objects contain different text.
bool StringMaker::operator!=(const StringMaker& other) const {
    return !(*this == other);
}

// Add the string on the left to the StringMaker on the right.
void operator>>(const std::string& addedString,
                StringMaker& sb) {

    sb.buffer += addedString;
}

// Send the StringMaker's buffer to an output stream such as cout.
std::ostream& operator<<(std::ostream& output,
                         StringMaker& sb) {

    output << sb.buffer;
    return output;
}