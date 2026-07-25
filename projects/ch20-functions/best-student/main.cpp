#include <iostream>
#include <array>
#include <algorithm>

struct Student {
    std::string name {};
    int points {};
};

int main() {
    std::array<Student, 8> arr {{ 
    { "Albert", 3 },
    { "Ben", 5 },
    { "Christine", 2 },
    { "Dan", 8 }, // Dan has the most points (8).
    { "Enchilada", 4 },
    { "Francis", 1 },
    { "Greg", 3 },
    { "Hagrid", 5 } 
    }};

    // Returns an iterator
    auto greater {
        [](const auto& s1, const auto& s2) {
            return s1.points < s2.points;
        }
    };

    const auto best_student{ std::max_element(arr.begin(), arr.end(), greater)};

    // Must dereference iterator to get element
    std::cout << best_student->name << " is the best student.\n";

    return 0;
}
