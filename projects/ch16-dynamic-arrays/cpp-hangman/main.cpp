#include "Random.h"
#include <iostream>
#include <string_view>
#include <vector>

bool validate_input();
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
};

void display_state(const Session& session, char guess) {
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
    
    std::cout << '\n';
}

char get_guesses(Session& session) {
    char input {};

    while (true) {        
        std::cout << "Enter you next letter: ";
        std::cin >> input;

        if(session.get_seen_letters()[static_cast<std::size_t>(input % 32) - 1]) {
            std::cout << "You already guessed that. Try again.\n";
            continue;
        }

        if (validate_input() && (input >= 'a' && input <= 'z'))
            break;

        std::cout << "That wasn't a valid input. Try again.\n";
    }

    session.update_seen(input);
    return input;
}

int main() {
    std::cout << "Welcome to C++man (a variant of Hangman)\n";
    std::cout << "To win: guess the word. To lose: run out of guesses\n";
    
    Session session {};

    for (auto e : session.get_seen_letters()) {
        std::cout << e << ' ';
    }

    std::cout << '\n';

    
    for (int i {0}; i < 6; ++i) {
        char c { get_guesses(session) };
        display_state(session, c);
    }

    for (auto e : session.get_seen_letters()) {
        std::cout << e << ' ';
    }

    std::cout << '\n';

	return 0;
}
