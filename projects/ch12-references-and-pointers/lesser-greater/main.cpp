#include <iostream>
#include <algorithm>

// When the function returns, the first argument should hold the lesser of the 
// two values, and the second argument should hold the greater of the two values.
void sort2(int& lesser, int& greater) {
    if (lesser > greater) {
        std::swap(lesser, greater);
    }
}


int main()
{
    int x { 7 };
    int y { 5 };

    std::cout << x << ' ' << y << '\n'; // should print 7 5

    sort2(x, y); // make sure sort works when values need to be swapped
    std::cout << x << ' ' << y << '\n'; // should print 5 7

    sort2(x, y); // make sure sort works when values don't need to be swapped
    std::cout << x << ' ' << y << '\n'; // should print 5 7

    return 0;
}
