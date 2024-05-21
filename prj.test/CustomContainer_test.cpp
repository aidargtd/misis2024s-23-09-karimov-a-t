#include <cassert>
#include <iostream>
#include "CustomContainer/IContainerBase.hpp"
#include "CustomContainer/CustomContainer.hpp"

void test_add() {
    CustomContainer container(3);
    container.add(1);
    assert(container.contains(1));
    assert(!container.contains(5));

    std::cout << "test_add passed!" << std::endl;
}

void test_remove() {
    CustomContainer container(3);
    container.add(3);

    assert(container.contains(3));
    container.remove(3);
    assert(!container.contains(3));

    std::cout << "test_remove passed!" << std::endl;
}

void test_operator_overloads() {
    CustomContainer container(3);
    container += 1;
    container += 2;
    container +=3;

    assert(container.contains(1));
    assert(container.contains(2));

    container -= 2;
    assert(!container.contains(2));

    CustomContainer container2(3);
    container2.add(1);
    container2.add(3);

    std::cout << container << std::endl;
    std::cout<< container2 << std::endl;
    assert(container==container2);
    std::cout << "test overloads passed!" << std::endl;
}


int main() {
    test_add();
    test_remove();
    test_operator_overloads();
    std::cout << "tests passed!" << std::endl;
}
