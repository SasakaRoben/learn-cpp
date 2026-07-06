#include "Random.h"
#include <iostream>
#include <string_view>

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

public:
    std::string_view get_word() const { return m_word; }
};

void display_state(const Session& session) {
    std::cout << '\n';
    
    std::cout << "The word: ";
    for ([[maybe_unused]] auto c : session.get_word()) {
        std::cout << '_';
    }
    std::cout << '\n';
}

int main() {
    std::cout << "Welcome to C++man (a variant of Hangman)\n";
    std::cout << "To win: guess the word. To lose: run out of guesses\n";
    
    Session session {};

    

	return 0;
}
