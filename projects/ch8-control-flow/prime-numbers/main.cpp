// Make sure that assert triggers even if we compile in release mode
#undef NDEBUG

#include <cassert> // for assert
#include <iostream>
#include <cmath>

bool is_prime(int x)
{
	if (x <= 1) {
		return false;
	}

	// 2 is the only even prime
	if (x == 2) {
		return true;
	}

	// Any other even number is not prime
	if (x % 2 == 0) {
		return false;
	}

	// For any number 3 or greater, test odd values (this is why we add 2)
    // between 3 and sqrt(x) to see if they are a divisor
    // Also see https://stackoverflow.com/questions/5811151/why-do-we-check-up-to-the-square-root-of-a-number-to-determine-if-the-number-is
    // Since test >= 0 and x >=0, we can optimize test < std::sqrt(x) to test * text < x
    for (int test{ 3 }; test * test <= x; test += 2)
    {
        if (x % test == 0) // if x is evenly divisible
            return false;  // then this number isn't prime
    }

	return true;
}

int main()
{
    assert(!is_prime(0)); // terminate program if is_prime(0) is true
    assert(!is_prime(1));
    assert(is_prime(2));  // terminate program if is_prime(2) is false
    assert(is_prime(3));
    assert(!is_prime(4));
    assert(is_prime(5));
    assert(is_prime(7));
    assert(!is_prime(9));
    assert(is_prime(11));
    assert(is_prime(13));
    assert(!is_prime(15));
    assert(!is_prime(16));
    assert(is_prime(17));
    assert(is_prime(19));
    assert(is_prime(97));
    assert(!is_prime(99));
    assert(is_prime(13417));

    std::cout << "Success!\n";

    return 0;
}
