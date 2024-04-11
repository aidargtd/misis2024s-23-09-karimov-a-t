#include "StackArrT/StackArrT.hpp"
#include <cassert>

void test_stack_operations() {
    // Создание пустого стека
    StackArrT<int> stack;
    assert(stack.empty());
    assert(stack.size() == 0);

    // Проверка на пустоту стека перед удалением элементов
    if (!stack.empty()) {
        stack.pop();
    }
    assert(stack.empty());
    assert(stack.size() == 0);

    // Добавление элементов в стек
    stack.push(5);
    assert(!stack.empty());
    assert(stack.size() == 1);
    assert(stack.top() == 5);

    stack.push(10);
    assert(stack.size() == 2);
    assert(stack.top() == 10);

    // Удаление элементов из стека
    if (!stack.empty()) {
        stack.pop();
    }
    assert(stack.size() == 1);
    assert(stack.top() == 5);

    if (!stack.empty()) {
        stack.pop();
    }
    assert(stack.empty());
    assert(stack.size() == 0);

    // Повторное добавление элементов и проверка на равенство и неравенство стеков
    stack.push(1);
    stack.push(2);
    stack.push(3);

    StackArrT<int> other_stack = stack;
    assert(stack == other_stack);

    if (!other_stack.empty()) {
        other_stack.pop();
    }
    assert(stack != other_stack);
}



int main() {
    test_stack_operations();
    return 0;
}
