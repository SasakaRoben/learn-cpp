#include <vector>
#include <iostream>
#include <cassert>

namespace Animals {
    enum Type {
        chicken, 
        dog, 
        cat, 
        elephant, 
        duck, 
        snake,
        max_types,
    };

    std::vector legs { 2, 4, 4, 4, 2, 0 };
}

int main() {
    assert(Animals::max_types == Animals::legs.size());
    std::cout << "An elephant has " 
              << Animals::legs[Animals::elephant] << " legs\n";

    return 0;
}
