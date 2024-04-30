#include "BinarySearchTree/BinarySearchTree.hpp"
#include <cassert>
#include <iostream>

void testAddAndFind() {
    BinarySearchTree bst;
    assert(bst.getRoot() == nullptr);  // Проверяем, что корень изначально nullptr

    bst.add(10);
    assert(bst.getRoot() != nullptr && bst.getRoot()->data == 10);  // Корень теперь должен содержать значение 10

    bst.add(5);
    bst.add(20);
    assert(bst.find(5) != nullptr && bst.find(5)->data == 5);  // Проверяем, что элемент 5 присутствует
    assert(bst.find(20) != nullptr && bst.find(20)->data == 20);  // Проверяем, что элемент 20 присутствует

    std::cout << "testAddAndFind passed!" << std::endl;
}

void testMinAndMax() {
    BinarySearchTree bst;
    bst.add(15);
    bst.add(10);
    bst.add(20);
    bst.add(8);
    bst.add(12);
    bst.add(17);
    bst.add(25);

    assert(bst.min() == 8);  // Минимум в дереве
    assert(bst.max() == 25); // Максимум в дереве

    std::cout << "testMinAndMax passed!" << std::endl;
}

void testRemove() {
    BinarySearchTree bst;
    bst.add(15);
    bst.add(10);
    bst.add(20);
    bst.add(8);
    bst.add(12);
    bst.add(17);
    bst.add(25);

    bst.remove(10); // Удаляем узел с одним потомком
    assert(bst.find(10) == nullptr);

    bst.remove(20); // Удаляем узел с двумя потомками
    assert(bst.find(20) == nullptr);

    bst.remove(15); // Удаляем корень
    assert(bst.getRoot()->data != 15);

    std::cout << "testRemove passed!" << std::endl;
}

void testEmptyTree() {
    BinarySearchTree bst;
    assert(bst.getRoot() == nullptr);
    assert(bst.find(10) == nullptr);
    try {
        bst.min();
        assert(false); // Ожидаем исключение, если не возникает, то assert false
    } catch (const std::runtime_error& e) {
        assert(true); // Исключение должно быть выброшено
    }
    try {
        bst.max();
        assert(false); // Также проверяем на максимум
    } catch (const std::runtime_error& e) {
        assert(true);
    }

    std::cout << "testEmptyTree passed!" << std::endl;
}

int main() {
    testAddAndFind();
    testMinAndMax();
    testRemove();
    testEmptyTree();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
