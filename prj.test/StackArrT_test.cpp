#include <cassert>
#include <iostream>
#include "StackArrT/StackArrT.hpp"

// Тест конструктора по умолчанию
void testDefaultConstructor() {
    StackArrT<int> stack;
    assert(stack.empty() && "Default constructor test failed: stack should be empty");
    std::cout << "Default constructor test passed!" << std::endl;
}

// Тест функции push и top
void testPushAndTop() {
    StackArrT<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    assert(stack.top() == 3 && "Push and top test failed: top element should be 3");
    std::cout << "Push and top test passed!" << std::endl;
}

// Тест функции pop
void testPop() {
    StackArrT<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.pop();
    assert(stack.top() == 2 && "Pop test failed: top element should be 2 after pop");
    stack.pop();
    assert(stack.top() == 1 && "Pop test failed: top element should be 1 after second pop");
    stack.pop();
    assert(stack.empty() && "Pop test failed: stack should be empty after popping all elements");
    std::cout << "Pop test passed!" << std::endl;
}

// Тест конструктора копирования
void testCopyConstructor() {
    StackArrT<int> stack1;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);

    StackArrT<int> stack2(stack1);
    assert(stack2.top() == 3 && "Copy constructor test failed: top element should be 3");
    stack2.pop();
    assert(stack2.top() == 2 && "Copy constructor test failed: top element should be 2 after pop");
    std::cout << "Copy constructor test passed!" << std::endl;
}

// Тест конструктора перемещения
void testMoveConstructor() {
    StackArrT<int> stack1;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);

    StackArrT<int> stack2(std::move(stack1));
    assert(stack2.top() == 3 && "Move constructor test failed: top element should be 3");
    stack2.pop();
    assert(stack2.top() == 2 && "Move constructor test failed: top element should be 2 after pop");
    assert(stack1.empty() && "Move constructor test failed: original stack should be empty");
    std::cout << "Move constructor test passed!" << std::endl;
}

// Тест функции merge
void testMerge() {
    StackArrT<int> stack1;
    stack1.push(1);
    stack1.push(2);

    StackArrT<int> stack2;
    stack2.push(3);
    stack2.push(4);

    stack1.merge(stack2);
    assert(stack1.size() == 4 && "Merge test failed: stack1 size should be 4 after merge");
    assert(stack1.top() == 4 && "Merge test failed: top element should be 4 after merge");
    stack1.pop();
    assert(stack1.top() == 3 && "Merge test failed: top element should be 3 after pop");
    std::cout << "Merge test passed!" << std::endl;
}

int main() {
    testDefaultConstructor();
    testPushAndTop();
    testPop();
    testCopyConstructor();
    testMoveConstructor();
    testMerge();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
