#include <vector>
#include <iostream>
#include <cassert>

namespace Items {
    enum Type {
        health_potions,
        torches,
        arrows,
        max_types,
    };
};

int count_total_items(const std::vector<int>& inventory) {
    int sum {};
    for (auto e : inventory) {
        sum += e;
    }

    return sum;
}

int main() {
    std::vector inventory { 1, 5, 10 };
    assert(Items::max_types == inventory.size() && "Arrays don't match");

    std::cout << "You have " << count_total_items(inventory) 
              << " total items\n";

    return 0;
}
