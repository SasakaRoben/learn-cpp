#include <iostream>
#include <iterator>

int main() {
    int array[] { 30, 50, 20, 10, 40 };
    constexpr int length { static_cast<int>(std::size(array)) };

    for (int start_index { 0 }; start_index < length - 1; ++start_index) {
        int largest_index { start_index };

        for (int current_index { start_index + 1 }; current_index < length;
             ++current_index) {
            if (array[current_index] > array[largest_index]) {
                largest_index = current_index;
            }
        }

        std::swap(array[start_index], array[largest_index]);
    }

    for (int index { 0 }; index < length; ++index) {
        std::cout << array[index] << " ";
    }
    
    std::cout << "\n";

    return 0;
}
