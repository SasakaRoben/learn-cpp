#include <iostream>
#include <vector>

void print_stack_values(const std::vector<int>& v) {
    std::cout << "\t(Stack:";

    for (auto e : v) {
        std::cout << ' ' << e;
    }

    if (v.empty()) {
        std::cout << " empty";
    }

    std::cout << ")\n";
}

void push_and_print(std::vector<int>& v, int val) {
    v.push_back(val);
    std::cout << "Push " << val;
    print_stack_values(v);
}

void pop_and_print(std::vector<int>& v) {
    v.pop_back();
    std::cout << "Pop ";
    print_stack_values(v);
}

int main() {
    std::vector<int> v {};

    print_stack_values(v);

    push_and_print(v, 1);
    push_and_print(v, 2);
    push_and_print(v, 3);
    pop_and_print(v);
    push_and_print(v, 4);
    pop_and_print(v);
    pop_and_print(v);
    pop_and_print(v);

    return 0;
}


