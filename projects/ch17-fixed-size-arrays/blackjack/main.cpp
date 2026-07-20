#include <array>
#include <iostream>
#include <cassert>
#include <algorithm> // For std::shuffle
#include "Random.h"

namespace Settings {
    // Maximum score before losing
    constexpr int bust { 21 };

    // Minimum score that dealer has to have.
    constexpr int dealer_stops_at { 17 };
}

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

class Player {
private:
    int m_score {};
    int m_ace11_count { 0 }; // How many aces worth 11 points the player has

public:
    void add_to_score(Card card) {
        m_score += card.value();
        if (card.rank == Card::rank_ace) {
            ++m_ace11_count; // aces start at 11 points
        }
        consume_aces();
    }

    // Decrease ace count by 1 
    void consume_aces() {
        // If the player would bust, see if we can switch aces from 11 points 
        // to 1 point
        while (m_score > Settings::bust && m_ace11_count > 0) {
            m_score -= 10;
            --m_ace11_count;
        }
    }

    int get_score() { return m_score; }
};


// Returns true if the dealer went bust. False otherwise
bool dealer_turn(Deck& deck, Player& dealer) {
    while (dealer.get_score() < Settings::dealer_stops_at) {
        Card card { deck.deal_card() };
        dealer.add_to_score(card);
        std::cout << "The dealer flips a " << card << ". They now have: "
                  << dealer.get_score() << "\n";
    }

    if (dealer.get_score() > Settings::bust) {
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
    while (player.get_score() < Settings::bust && player_wants_hit()) {
        Card card { deck.deal_card() };
        player.add_to_score(card);

        std::cout << "You were dealt " << card << ". You now have: "
                  << player.get_score() << "\n";
    }

    if (player.get_score() > Settings::bust) {
        std::cout << "You went bust!\n";
        return true;
    }

    return false;
}

enum class GameResult {
    player_won,
    dealer_won,
    tie,
};

GameResult play_black_jack() {
    Deck deck {};
    deck.shuffle();

    Player dealer {};
    Card dealer_card1 { deck.deal_card() };
    dealer.add_to_score(dealer_card1);

    std::cout << "The dealer is showing: " << dealer_card1 << " (" 
              << dealer.get_score() << ")\n";

    Player player {};
    Card player_card1 { deck.deal_card() };
    Card player_card2 { deck.deal_card() };
    player.add_to_score(player_card1);
    player.add_to_score(player_card2);
    std::cout << "You are showing " << player_card1 << " " << player_card2
              << " (" << player.get_score() << ")\n";

    // If player busted
    if (player_turn(deck, player)) {
        return GameResult::dealer_won;
    }

    // If dealer busted
    if (dealer_turn(deck, dealer)) {
        return GameResult::player_won;
    }

    if (player.get_score() == dealer.get_score()) {
        return GameResult::tie;
    }

    return (player.get_score() > dealer.get_score() ? 
            GameResult::player_won : GameResult::dealer_won);
}

int main() {
    switch (play_black_jack()) {
        case GameResult::player_won:
            std::cout << "You win!\n";
            return 0;
        case GameResult::dealer_won:
            std::cout << "You lose!\n";
            return 0;
        case GameResult::tie:
            std::cout << "It's a tie.\n";
            return 0;
    }

    return 0;
}
