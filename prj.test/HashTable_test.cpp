#include <iostream>
#include <vector>
#include <cassert>
#include "HashTable/HashTable.hpp"

void testAddingAndReturningIntKeysAndValues() {
    HashTable<int, int> table;
    int i = 0, j = 100;
    while (i < 100 && j > 0) {
        table.add(i, j);
        ++i;
        --j;
    }

    i = 0;
    j = 100;
    while (i < 100 && j > 0) {
        assert(table.exists(i) == true);
        ++i;
        --j;
    }

    for (auto x : table) {
        assert(table[x.first] == x.second);
    }

    HashTable<int, int> table2;
    i = 0;
    j = 10;
    while (i < 10 && j > 0) {
        table2.add(i, j);
        ++i;
        --j;
    }

    i = 0;
    j = 10;
    while (i < 10 && j > 0) {
        assert(table2.exists(i) == true);
        ++i;
        --j;
    }

    for (auto x : table2) {
        assert(table2[x.first] == x.second);
    }
}

void testBorderCases() {
    HashTable<int, int> table;
    std::vector<int> borders = {3, 15, 23, 42, 29};
    int i = 0, j = 100;
    while (i < 100 && j > 0) {
        if (std::find(borders.begin(), borders.end(), i) == borders.end()) {
            table.add(i, j);
        }
        ++i;
        --j;
    }

    for (auto x : table) {
        assert(table.exists(x.first) == true);
        assert(table[x.first] == x.second);
    }
}

void testAddingAndReturningStringKeysAndValues() {
    HashTable<std::string, std::string> table;
    for (int i = 0; i < 50; ++i) {
        std::string key = "key" + std::to_string(i);
        std::string value = "value" + std::to_string(i);
        table.add(key, value);
    }

    for (int i = 0; i < 50; ++i) {
        std::string key = "key" + std::to_string(i);
        std::string value = "value" + std::to_string(i);
        assert(table.exists(key) == true);
        assert(table[key] == value);
    }

    for (auto x : table) {
        assert(table[x.first] == x.second);
    }
}

void testAddingAndReturningDoubleValues() {
    HashTable<double, double> table;
    double i = 1.1, j = 100.5;
    while (i < 100.1 && j > 0.5) {
        table.add(i, j);
        i += 1.0;
        j -= 1.0;
    }

    i = 1.1;
    j = 100.5;
    while (i < 100.1 && j > 0.5) {
        assert(table.exists(i) == true);
        i += 1.0;
        j -= 1.0;
    }

    for (auto x : table) {
        assert(table[x.first] == x.second);
    }

    HashTable<double, double> table2;
    i = 1.1;
    j = 10.5;
    while (i < 10.1 && j > 0.5) {
        table2.add(i, j);
        i += 1.0;
        j -= 1.0;
    }

    i = 1.1;
    j = 10.5;
    while (i < 10.1 && j > 0.5) {
        assert(table2.exists(i) == true);
        i += 1.0;
        j -= 1.0;
    }

    for (auto x : table2) {
        assert(table2[x.first] == x.second);
    }
}

int main() {
    testAddingAndReturningIntKeysAndValues();
    testBorderCases();
    testAddingAndReturningStringKeysAndValues();
    testAddingAndReturningDoubleValues();

    std::cout << "All tests passed" << std::endl;
    return 0;
}
