#include <iostream>
#include <cassert>
#include "StackLstT/StackLstT.hpp"


int main() {
    // Test default constructor
    StackLstT<int> stack;
    assert(stack.empty());
    assert(stack.size() == 0);

    // Test push and top
    stack.push(10);
    assert(!stack.empty());
    assert(stack.size() == 1);
    assert(stack.top() == 10);

    stack.push(20);
    assert(stack.size() == 2);
    assert(stack.top() == 20);

    // Test copy constructor
    StackLstT<int> stack_copy(stack);
    assert(stack_copy.size() == 2);
    assert(stack_copy.top() == 20);

    // Test pop
    stack.pop();
    assert(stack.size() == 1);
    assert(stack.top() == 10);

    // Test move constructor
    StackLstT<int> stack_move(std::move(stack));
    assert(stack_move.size() == 1);
    assert(stack_move.top() == 10);
    assert(stack.empty());

    // Test initializer list constructor
    StackLstT<int> stack_init_list({1, 2, 3, 4, 5});
    assert(stack_init_list.size() == 5);
    assert(stack_init_list.top() == 5);

    // Test swap
    stack_init_list.swap(stack_move);
    assert(stack_init_list.size() == 1);
    assert(stack_init_list.top() == 10);
    assert(stack_move.size() == 5);
    assert(stack_move.top() == 5);

    // Test merge
    StackLstT<int> stack_to_merge({100, 200, 300});
    stack_init_list.merge(stack_to_merge);
    assert(stack_init_list.size() == 8);
    assert(stack_init_list.top() == 300);

    // Test comparison operators
    assert(stack_init_list != stack_to_merge);
    stack_to_merge.pop();
    stack_to_merge.pop();
    stack_to_merge.pop();
    assert(stack_init_list == stack_to_merge);

    // Test assignment operator
    stack_move = stack_init_list;
    assert(stack_move.size() == 8);
    assert(stack_move.top() == 300);

    // Test move assignment operator
    StackLstT<int> stack_temp(std::move(stack_init_list));
    assert(stack_temp.size() == 8);
    assert(stack_temp.top() == 300);

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
