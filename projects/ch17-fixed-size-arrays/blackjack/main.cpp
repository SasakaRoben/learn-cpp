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

int main() {
    // Print one card
    Card card { Card::rank_5, Card::suit_heart };
    std::cout << card << '\n';

    // Print all cards
    for (auto suit : Card::all_suits)
        for (auto rank : Card::all_ranks)
            std::cout << Card { rank, suit } << ' ';
    std::cout << '\n';

    return 0;
}
