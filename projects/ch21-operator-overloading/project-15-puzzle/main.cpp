#include <iostream>

// Increase amount of new lines if your board isn't 
// at the very bottom of the console
constexpr int g_console_lines { 25 };
class Tile {
private:
    int m_num { 0 };

public:
    Tile() = default;
    explicit Tile(int number)
        : m_num { number }
    {}

    bool is_empty() const {
        return m_num == 0;
    }

    int get_num() const {
        return m_num;
    }
};

std::ostream& operator<<(std::ostream& stream, Tile tile) {
    // if two digit number
    if (tile.get_num() > 9) {
        stream << " " << tile.get_num() << " ";
    }
    // if one digit number
    else if (tile.get_num() > 0) {
        stream << "  " << tile.get_num() << " ";
    }
    // if empty spot
    else if (tile.get_num() == 0) {
        stream << "    ";
    }
    return stream;
}

class Board {
private:
    static constexpr int s_size { 4 };
    Tile m_tiles[s_size][s_size] {
        Tile {1}, Tile {2}, Tile {3}, Tile {4},
        Tile {5}, Tile {6}, Tile {7}, Tile {8},
        Tile {9}, Tile {10}, Tile {11}, Tile {12},
        Tile {13}, Tile {14}, Tile {15}, Tile {0}
    };

public:
    Board() = default;

    friend std::ostream& operator<<(std::ostream& stream, const Board& board) {
        // Before drawing, always print some empty lines
        // so that only one board appears at a time
        // and it's always shown at the bottom of the window
        // because console window scrolls automatically when there is no
        // enough space
        for (int i = 0; i < g_console_lines; ++i) {
            std::cout << '\n';
        }

        for (int y = 0; y < s_size; ++y) {
            for (int x = 0; x < s_size; ++x) {
                stream << board.m_tiles[y][x];
            }
            stream << '\n';
        }

        return stream;
    }
};

int main()
{
    Board board{};
    std::cout << board;

    return 0;
}
