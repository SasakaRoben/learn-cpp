#include <array>
#include <iostream>

template <typename T, std::size_t N>
void print_array(const std::array<T, N>& arr) {
    bool comma { false };
    
    std::cout << "The array ( ";
    for (const auto& e : arr) {
        if (comma) {
            std::cout << ", ";
        }

        std::cout << e;
        comma = true;
    }
    std::cout << " ) has length " << N << '\n';
}

int main() {
    constexpr std::array arr1 { 1, 4, 9, 16 };
    print_array(arr1);

    constexpr std::array arr2 { 'h', 'e', 'l', 'l', 'o' };
    print_array(arr2);

    return 0;
}
