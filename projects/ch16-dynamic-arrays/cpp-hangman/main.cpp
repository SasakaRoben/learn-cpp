#include "Random.h"
#include <iostream>
#include <string_view>
#include <vector>

bool validate_input();

namespace Settings {
    constexpr int wrong_guesses_allowed { 6 };
}
namespace WorldList {
    std::vector <std::string_view> words { "mystery", "broccoli", "account", 
                                      "almost", "spaghetti", "opinion", 
                                      "beautiful", "distance", "luggage" };

    std::string_view get_random_word() {
        return words[Random::get<std::size_t>(0, WorldList::words.size()-1)];
    }
}

class Session {
private:
    std::string_view m_word { WorldList::get_random_word() };
    std::vector<bool> m_letter_guessed { std::vector<bool>(26) };
    int m_wrong_guesses_left { Settings::wrong_guesses_allowed };

    std::size_t to_index(char c) const {
        return static_cast<std::size_t>((c % 32) - 1);
    }

public:
    std::string_view get_word() const { return m_word; }

    bool is_letter_guessed(char c) const { 
        return m_letter_guessed[to_index(c)];
    }

    void set_letter_guessed(char c) {
        m_letter_guessed[to_index(c)] = true;
    }

    int wrong_guesses_left() const { return m_wrong_guesses_left; }
    void remove_guess() { --m_wrong_guesses_left; }

    bool is_letter_in_word(char c) const {
        for (auto ch : m_word) {
            if (ch == c) {
                return true;
            }
        }
        return false;
    }

    bool won() {
        for (auto c : m_word) {
            if (!is_letter_guessed(c)) {
                return false;
            }
        }

        return true;
    }
};

void display_state(const Session& session) {
    std::cout << '\n';
    
    std::cout << "The word: ";
    for (auto c : session.get_word()) {
        if (session.is_letter_guessed(c)) {
            std::cout << c;
        }
        else {
            std::cout << '_';
        }
    }

    std::cout << " Wrong guesses: ";
    for (int i { 0 }; i < session.wrong_guesses_left(); i++) {
        std::cout << '+';
    }

    for (char c = 'a'; c <= 'z'; ++c) {
        if (session.is_letter_guessed(c) && !session.is_letter_in_word(c)) {
            std::cout << c;
        }
    }

    std::cout << '\n';
}

char get_guess(const Session& session) {
    char input {};

    while (true) {        
        std::cout << "Enter you next letter: ";
        std::cin >> input;

        if(session.is_letter_guessed(input)) {
            std::cout << "You already guessed that. Try again.\n";
            continue;
        }

        if (validate_input() && (input >= 'a' && input <= 'z'))
            break;

        std::cout << "That wasn't a valid input. Try again.\n";
    }

    return input;
}

int main() {
    std::cout << "Welcome to C++man (a variant of Hangman)\n";
    std::cout << "To win: guess the word. To lose: run out of guesses\n";
    
    Session session {};

    for (int i {0}; i < 6; ++i) {
        display_state(session);
        char c { get_guess(session) };
        session.set_letter_guessed(c);
    }

    display_state(session);


	return 0;
}
