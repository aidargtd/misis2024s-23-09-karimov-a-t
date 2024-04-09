#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "StackArrT/StackArrT.hpp"


TEST_CASE_TEMPLATE("Testing StackArrT functionality", T, int, float, double, long long) {
    StackArrT<T> stack;

    SUBCASE("Newly created stack is empty") {
        CHECK(stack.empty());
        CHECK(stack.size()==0);
    }

    SUBCASE("Push and top operations") {
        stack.push(1);
        CHECK(stack.top() == 1);
        CHECK(stack.empty() == false);
        CHECK(stack.size() == 1);

        stack.push(2);
        CHECK(stack.top() == 2);
        CHECK(stack.size() == 2);
    }

    SUBCASE("Pop operation") {
        stack.push(1);
        stack.push(2);
        stack.pop();
        CHECK(stack.top() == 1);
        CHECK(stack.size() == 1);
    }

    SUBCASE("Copy constructor") {
        stack.push(1);
        stack.push(2);
        StackArrT<T> stackCopy(stack);
        CHECK(stackCopy.size() == 2);
        CHECK(stackCopy.top() == 2);

        stack.pop();
        stack.pop(); // Clear the original stack
        // Ensure the copy is independent
        CHECK(stackCopy.size() == 2);
        CHECK(stackCopy.top() == 2);
    }

    SUBCASE("Move constructor") {
        stack.push(1);
        stack.push(2);
        StackArrT<T> stackMoved(std::move(stack));
        CHECK(stackMoved.size() == 2);
        CHECK(stackMoved.top() == 2);
        // Original stack should be empty after the move
        CHECK(stack.empty() == true);
    }

    SUBCASE("Equality and inequality operators") {
        StackArrT<T> stack1;
        StackArrT<T> stack2;
        stack1.push(1);
        stack2.push(1);

        CHECK(stack1 == stack2);

        stack2.push(2);
        CHECK(stack1 != stack2);
    }
}
