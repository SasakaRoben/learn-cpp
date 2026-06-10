// Simulate free fall
// Ask for tower height in meters
// Assume normal gravity of 9.8 m/s^2 and ball has no initial velocity
// Output the height of the ball after 0, 1, 2, 3, 4, and 5 seconds
// The ball should not go below the ground (height of 0 meters)

#include <iostream>

double get_height() {
    std::cout << "Enter the height of the tower in meters: ";
    double tower_height {};
    std::cin >> tower_height;
    return tower_height;
}

double calculate_height(int seconds, double tower_height) {
    double gravity_constant { 9.8 };

    // Using formula: s = (u * t) + (a * t^2) / 2
	// here u (initial velocity) = 0, so (u * t) = 0
    double fall_distance { ((gravity_constant * (seconds * seconds)) / 2) };
    double current_height { tower_height - fall_distance };

    if (current_height < 0.0) {
        current_height = 0.0;
    }
    return current_height;
}

void print_current_height(int seconds, double tower_height) {
    double current_height { (calculate_height(seconds, tower_height)) };
    if (current_height > 0.0) {
        std::cout << "At " << seconds << " seconds, the ball is at height: "
                  << current_height << " meters\n";
    }
    else {
        std::cout << "At " << seconds << 
                  " seconds, the ball is on the ground.\n";
    }
}

int main() {
    std::cout << "Enter the height of the tower in meters: ";
    double height {get_height()};
    print_current_height(0, height);
    print_current_height(1, height);
    print_current_height(2, height);
    print_current_height(3, height);
    print_current_height(4, height);
    print_current_height(5, height);

    return 0;
}
