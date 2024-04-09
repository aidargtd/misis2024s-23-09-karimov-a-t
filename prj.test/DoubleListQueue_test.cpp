#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "DoubleListQueue/DoubleListQueue.hpp"

TEST_CASE("Testing DoubleListQueue") {
    DoubleListQueue queue;

    SUBCASE("New queue is empty") {
        CHECK(queue.empty());
        CHECK(!queue.getSize());
    }

    SUBCASE("Pushing items") {
        queue.push(10);
        CHECK(queue.empty() == false);
        CHECK(queue.getSize() == 1);
        CHECK(queue.getFront() == 10);
        CHECK(queue.getBack() == 10);

        queue.push(20);
        CHECK(queue.getSize() == 2);
        CHECK(queue.getFront() == 10);
        CHECK(queue.getBack() == 20);
    }

    SUBCASE("front and back") {
        queue.push(10);
        queue.push(20);
        CHECK(queue.getFront() == 10);
        CHECK(queue.getBack() == 20);
    }

    SUBCASE("checking top") {
        queue.push(10);
        queue.push(20);
        CHECK(queue.top() == 10);
        CHECK(queue.empty() == false);
        CHECK(queue.getSize() == 1);
        CHECK(queue.getFront() == 20);
        CHECK(queue.top() == 20);
        CHECK(queue.empty() == true);
        CHECK(queue.getSize() == 0);
    }
}
