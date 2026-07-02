#include <iostream>
#include <limits> // for std::numeric_limits

// Clears any extraneous input
void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Returns true if extraction failed, false otherwise
bool clear_failed_extraction() {
    
    // Check for failed extraction
    if (!std::cin) {

        // If the stream was closed
        if (std::cin.eof()) {
            std::exit(0); // Shut down the program now
        }
        
        // Let's handle the failure
        std::cin.clear(); // Put us back in 'normal' operation mode
        ignore_line(); // And remove the bad inputs

        return true;
    }
    
    return false;
}

// Returns true if std::cin has unextracted input on the current line, false otherwise
bool has_unextracted_input() {
    return !std::cin.eof() && std::cin.peek() != '\n';
}

// Returns true if the input was fully valid, false otherwise.
// Always leaves std::cin clean (no leftover bad input) either way.
bool validate_input() {
    if (clear_failed_extraction()) // e.g. user typed "abc" for an int
        return false;

    // e.g. user typed "5*7" — 5 extracted, "*7" left over
    if (has_unextracted_input()) {
        ignore_line();
        return false;
    }

    // Only safe to ignore() if the stream is still good;
    if (!std::cin.eof()) {
        ignore_line();    // calling it after EOF would spuriously set failbit
    }

    return true;
}
