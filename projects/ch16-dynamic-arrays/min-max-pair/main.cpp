#include <vector>
#include <utility>
#include <iostream>

template <typename T>
std::pair<std::size_t, std::size_t> get_min_max_indices(
    const std::vector<T>& arr) {

    std::size_t min_index { 0 };
    std::size_t max_index { 0 };

    for (std::size_t index {1}; index < arr.size(); ++index) {
        if (arr[index] < arr[min_index]) {
            min_index = index;
        }
        else if (arr[index] > arr[max_index]) {
            max_index = index;
        }
    }

    return { min_index, max_index };
}

template <typename T>
void print_array(const std::vector<T>& arr) {
    bool comma { false };
    
    std::cout << "With array ( ";
    for (const auto& e : arr) {
        if (comma) {
            std::cout << ", ";
        }

        std::cout << e;
        comma = true;
    }
    std::cout << " ):\n";
}

int main() {
    std::vector v1 { 3, 8, 2, 5, 7, 8, 3 };
    print_array(v1);

    auto p1 { get_min_max_indices(v1) };
    std::cout << "The min element has index " << p1.first 
              << " and value " << v1[p1.first] << '\n';
    std::cout << "The max element has index " << p1.second 
              << " and value " << v1[p1.second] << '\n';

    std::cout << '\n';

    std::vector v2 { 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 };
    print_array(v2);

    auto p2 { get_min_max_indices(v2) };
    std::cout << "The min element has index " << p2.first 
              << " and value " << v2[p2.first] << '\n';
    std::cout << "The max element has index " << p2.second 
              << " and value " << v2[p2.second] << '\n';

    return 0;
}
