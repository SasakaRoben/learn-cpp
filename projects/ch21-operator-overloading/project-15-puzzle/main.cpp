#include <iostream>
#include <limits>
#include <array>
#include <cassert>
#include "Random.h"

// Increase amount of new lines if your board isn't 
// at the very bottom of the console
constexpr int g_console_lines { 25 };

class Direction {
public:
    enum Type {
        up,
        down,
        left,
        right,
        max_directions,
    };

    Direction(Type type)
        : m_type {type}
    {}

    Type get_type() const {
        return m_type;
    }

    Direction operator-() const {
        switch (m_type) {
            case up:    return Direction { down };
            case down:  return Direction { up };
            case left:  return Direction { right };
            case right: return Direction { left };
            default:    break;
        }

        assert(0 && "Unsupported direction was passed!");
        return Direction { up };
    }

    static Direction get_random_direction() {
        Type random { 
            static_cast<Type>(Random::get(0, Type::max_directions - 1)) };
        return Direction { random };
    }

private:
    Type m_type {};
};

std::ostream& operator<<(std::ostream& stream, Direction dir) {
    switch(dir.get_type()) {
        case Direction::up:     return (stream << "up");
        case Direction::down:   return (stream << "down");
        case Direction::left:   return (stream << "left");
        case Direction::right:  return (stream << "right");
        default:                break;
    }

    assert(0 && "Unsupported direction was passed!");
    return (stream << "Unknown direction");
}

struct Point {
    int x {};
    int y {};

    friend bool operator==(Point p1, Point p2) {
        return p1.x == p2.x && p1.y == p2.y;
    }

    friend bool operator!=(Point p1, Point p2) {
        return !(p1 == p2);
    }

    Point get_adjacent_point(Direction dir) const {
        switch(dir.get_type()) {
            case Direction::up:     return Point{ x,     y - 1 };
            case Direction::down:   return Point{ x,     y + 1 };
            case Direction::left:   return Point{ x - 1, y };
            case Direction::right:  return Point{ x + 1, y };
            default:                break;
        }

        assert(0 && "Unsupported direction was passed!");
        return *this;
    }
};

namespace UserInput {
    bool is_valid_command(char ch) {
        return ch == 'w'
            || ch == 'a'
            || ch == 's'
            || ch == 'd'
            || ch == 'q';
    }

    void ignore_line() {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    char get_character() {
        char operation {};
        std::cin >> operation;
        ignore_line(); // remove any extraneous input
        return operation;
    }

    char get_command_from_user() {
        char ch {};
        while (!is_valid_command(ch)) {
            ch = get_character();
        }

        return ch;
    }

    Direction char_to_direction(char ch) {
        switch(ch) {
            case 'w': return Direction{ Direction::up };
            case 's': return Direction{ Direction::down };
            case 'a': return Direction{ Direction::left };
            case 'd': return Direction{ Direction::right };
        }

        assert(0 && "Unsupported direction was passed!");
        return Direction{ Direction::up };
    }
};
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

    static void print_empty_lines(int count) {
        for (int i = 0; i < count; ++i)
            std::cout << '\n';
    }


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

    Point get_empty_tile_pos() const {
        for (int y { 0 }; y < s_size; ++y) {
            for (int x { 0 }; x < s_size; ++x) {
                if (m_tiles[y][x].is_empty()) {
                    return { x,y };
                }
            }
        }

        assert(0 && "There is no empty tile in the board!!!");
        return { -1,-1 };
    }

    static bool is_valid_tile_pos(Point pt) {
        return (pt.x >= 0 && pt.x < s_size)
            && (pt.y >= 0 && pt.y < s_size);
    }

    void swap_tiles(Point pt1, Point pt2) {
        std::swap(m_tiles[pt1.y][pt1.x], m_tiles[pt2.y][pt2.x]);
    }

    // Returns true if user moved successfully
    bool move_tile(Direction dir) {
        Point empty_tile { get_empty_tile_pos() };
        Point adj { empty_tile.get_adjacent_point(-dir) };
        
        if (!is_valid_tile_pos(adj)) {
            return false;
        }

        swap_tiles(adj, empty_tile);
        return true;
    }

};

int main()
{
    Board board{};
    std::cout << board;

    std::cout << "Enter a command: ";
    while (true)
    {
        char ch{ UserInput::get_command_from_user() };

        // Handle non-direction commands
        if (ch == 'q')
        {
            std::cout << "\n\nBye!\n\n";
            return 0;
        }

        // Handle direction commands
        Direction dir{ UserInput::char_to_direction(ch) };

        bool userMoved { board.move_tile(dir) };
        if (userMoved)
            std::cout << board;
    }

    return 0;
}
