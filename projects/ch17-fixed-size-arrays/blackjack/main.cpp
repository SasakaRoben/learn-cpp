#include <array>
#include <iostream>
#include <cassert>
#include <algorithm> // For std::shuffle
#include "Random.h"

struct Card {
    enum Rank {
        rank_ace,
        rank_2,
        rank_3,
        rank_4,
        rank_5,
        rank_6,
        rank_7,
        rank_8,
        rank_9,
        rank_10,
        rank_jack,
        rank_queen,
        rank_king,

        max_ranks
    };

    enum Suit {
        suit_club,
        suit_diamond,
        suit_heart,
        suit_spade,

        max_suits
    };

    Rank rank{};
    Suit suit{};

    // Static so they are created once per program, not once per card
    static constexpr std::array<Rank, max_ranks> all_ranks
    { rank_ace, rank_2,rank_3,rank_4,rank_5,rank_6,rank_7,rank_8,rank_9,
      rank_10, rank_jack,rank_queen, rank_king };

    static constexpr std::array<Suit, max_suits> all_suits 
    { suit_club, suit_diamond, suit_heart, suit_spade };

    friend std::ostream& operator<<(std::ostream& out, const Card &card) {
        static constexpr std::array ranks { 'A', '2', '3', '4', '5', '6', '7', 
                                            '8', '9', 'T', 'J', 'Q', 'K' };
        static constexpr std::array suits { 'C', 'D', 'H', 'S' };

        out << ranks[card.rank] << suits[card.suit];
        return out;
    }

    int value() const {
        static constexpr std::array rank_values { 11, 2, 3, 4, 5, 6, 7, 8, 9, 
                                                  10, 10, 10, 10 };
    }
};

class Deck {
private:
    std::array<Card, 52> m_cards {};
    std::size_t m_next_card_index { 0 };
    
public:
    Deck() {
        std::size_t count { 0 };
        for (auto suit : Card::all_suits) {
            for (auto rank : Card::all_ranks) {
                m_cards[count++] = Card {rank, suit};
            }
        }
    }

    void shuffle() {
        std::shuffle(m_cards.begin(), m_cards.end(), Random::mt);
        m_next_card_index = 0;
    }

    Card deal_card() {
        assert(m_next_card_index != 52 && "Deck::deal_card ran out of cards");
        return m_cards[m_next_card_index];
    }
};

struct Player {
    int score {};
};

namespace Settings {
    // Maximum score before losing
    constexpr int bust { 21 };

    // Minimum score that dealer has to have.
    constexpr int dealer_stops_at { 17 };
}

// Returns true if the dealer went bust. False otherwise
bool dealer_turn(Deck& deck, Player& dealer) {
    while (dealer.score < Settings::dealer_stops_at) {
        Card card { deck.deal_card() };
        dealer.score += card.value();
        std::cout << "The dealer flips a " << card << ". They now have: "
                  << dealer.score << "\n";
    }

    if (dealer.score > Settings::bust) {
        std::cout << "The dealer went bust!\n";
        return true;
    }

    return false;
}

bool player_wants_hit() {
    while (true) {
        std::cout << "(h) to hit, or (s) to stand: ";

        char ch {};
        std::cin >> ch;

        switch(ch) {
            case 'h':
                return true;
            case 's':
                return false;
        }
    }
}

// Returns true if the player went bust. False otherwise
bool player_turn(Deck& deck, Player& player) {
    while (player.score < Settings::bust && player_wants_hit()) {
        Card card { deck.deal_card() };
        player.score += card.value();

        std::cout << "You were dealt " << card << ". You now have: "
                  << player.score << "\n";
    }

    if (player.score > Settings::bust) {
        std::cout << "You went bust!\n";
        return true;
    }

    return false;
}

bool play_black_jack() {
    Deck deck {};
    deck.shuffle();

    Player dealer { deck.deal_card().value() };

    std::cout << "The dealer is showing: " << dealer.score << "\n";

    Player player { deck.deal_card().value() + deck.deal_card().value() };

    std::cout << "You have score: " << player.score << "\n";

    if (player_turn(deck, player)) {
        return false;
    }

    if (dealer_turn(deck, dealer)) {
        return true;
    }

    return (player.score > dealer.score);
}

int main() {
    if (play_black_jack()) {
        std::cout << "You win!\n";
    }
    else {
        std::cout << "You lose!\n";
    }

    return 0;
}
