#include <iostream>
#include <iterator>

int main() {
    int array[] { 6, 3, 2, 9, 7, 1, 5, 4, 8 };
    constexpr std::size_t length { std::size(array) };

    // Step through each element of the array (except the last, which will
    // already be sorted by the time we get to it)
    for (std::size_t iteration { 0 }; iteration < length-1; ++iteration) {
        for (std::size_t current_index { 0 }; current_index < length-1; 
             ++current_index) {
            // Search through all the elements up to the end of the array-1
            // The last element has no pair to compare against
            if (array[current_index] > array[current_index+1]) {
                std::swap(array[current_index], array[current_index+1]);
            }
        }
    }

    for (std::size_t index { 0 }; index < length; ++index) {
        std::cout << array[index] << " ";
    }

    std::cout << "\n";

    return 0;
}
