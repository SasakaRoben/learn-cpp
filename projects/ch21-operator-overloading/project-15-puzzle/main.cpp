#include <iostream>

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

int main() {
    Tile tile1{ 10 };
    Tile tile2{ 8 };
    Tile tile3{ 0 }; // the missing tile
    Tile tile4{ 1 };

    std::cout << "0123456789ABCDEF\n"; // to make it easy to see how many spaces are in the next line
    std::cout << tile1 << tile2 << tile3 << tile4 << '\n';


}
