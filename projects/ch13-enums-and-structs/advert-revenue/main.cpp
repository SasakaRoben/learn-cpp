#include <iostream>

struct Advertising {
    int ads_shown {};
    double click_through_rate_percentage {};
    double average_earnings_per_click {};
};

Advertising get_advertising() {
    Advertising temp {};

    std::cout << "How many ads were shown today? ";
    std::cin >> temp.ads_shown;

    std::cout << "What percentage of ads were clicked on by users? ";
    std::cin >> temp.click_through_rate_percentage;

    std::cout << "What was the average earnings per click? ";
    std::cin >> temp.average_earnings_per_click;

    return temp;
}

void print_advertising(const Advertising& ad) {
    std::cout << "Number of ads shown: " << ad.ads_shown << '\n';
    std::cout << "Click through rate: "
              << ad.click_through_rate_percentage << '\n';
    std::cout << "Average earnings per click: "
              << ad.average_earnings_per_click << '\n';

    std::cout << "Total earnings: $" 
              << ad.ads_shown * (ad.click_through_rate_percentage / 100)
                 * ad.average_earnings_per_click << '\n'; 
}

int main() {
    Advertising ad { get_advertising() };
    print_advertising(ad);

    return 0;
}
