#include <vector>
#include <utility>
#include <iostream>

bool validate_input();

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

std::vector<int> get_array() {
    std::vector<int> arr {};

    while (true)
	{
		std::cout << "Enter numbers to add (use -1 to stop): ";
		int input {};
		std::cin >> input;

        // If we're done, break out of loop
		if (input == -1) {
			break;
        }

		if (!validate_input()) {
            std::cout << "Invalid Input.\n";
            continue;
        }

		// The user entered a valid element, so let's push it on the vector
		arr.push_back(input);
	}

    return arr;
}

int main() {
    std::vector v1 { get_array() };
    
    if (v1.size() > 0) {
        print_array(v1);

        auto p1 { get_min_max_indices(v1) };
        std::cout << "The min element has index " << p1.first 
                << " and value " << v1[p1.first] << '\n';
        std::cout << "The max element has index " << p1.second 
                << " and value " << v1[p1.second] << '\n';
    }
    else {
        std::cout << "Array is empty.\n";
    }
    
    return 0;
}
