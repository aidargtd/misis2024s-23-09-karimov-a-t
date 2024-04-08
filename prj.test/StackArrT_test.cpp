#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <StackArrT/StackArrT.сpp>
#include <rational/rational.hpp>

TEST_CASE("Testing StackArrT with int") {
    StackArrT<int> stack;
    CHECK(stack.empty());

    stack.push(1);
    stack.push(2);
    stack.push(3);
    CHECK(stack.size() == 3);
    CHECK(stack.top() == 3);

    stack.pop();
    CHECK(stack.top() == 2);
    CHECK(stack.size() == 2);
}

TEST_CASE("Testing StackArrT with float") {
    StackArrT<float> stack;
    stack.push(1.1f);
    stack.push(2.2f);
    CHECK(stack.size() == 2);
    CHECK(doctest::Approx(stack.top()) == 2.2f);

    stack.pop();
    CHECK(doctest::Approx(stack.top()) == 1.1f);
}


TEST_CASE("Testing StackArrT with custom Rational class") {
    StackArrT<Rational> stack;
    Rational r1(1, 2);
    Rational r2(3, 4);

    stack.push(r1);
    stack.push(r2);
    CHECK(stack.size() == 2);
    CHECK(stack.top() == r2);

    stack.pop();
    CHECK(stack.top() == r1);
}


