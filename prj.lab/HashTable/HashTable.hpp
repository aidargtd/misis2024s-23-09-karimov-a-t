#pragma once

#include <iostream>
#include <vector>
#include <functional>
#include <stdexcept>
#include <utility>

template<typename K, typename V>
class HashTable {
private:
    struct Entry {
        K key;
        V value;
        Entry* next;

        Entry(const K& k, const V& v) : key(k), value(v), next(nullptr) {}
    };

    std::vector<Entry*> buckets;
    std::hash<K> hash_function;

public:
    HashTable() {
        for (int i = 0; i < 16; ++i) {
            buckets.push_back(nullptr);
        }
    }

    void add(const K& key, const V& value);
    bool exists(const K& key) const;
    V& operator[](const K& key);

    class Iterator {
    private:
        size_t current_index;
        Entry* current_entry;
        const std::vector<Entry*>& buckets_ref;

    public:
        Iterator(size_t idx, Entry* node, const std::vector<Entry*>& buckets)
                : current_index(idx), current_entry(node), buckets_ref(buckets) {}

        Iterator& operator++() {
            if (current_entry && current_entry->next) {
                current_entry = current_entry->next;
            } else {
                size_t next_index = current_index + 1;
                while (next_index < buckets_ref.size() && !buckets_ref[next_index]) {
                    ++next_index;
                }
                current_index = next_index;
                current_entry = next_index < buckets_ref.size() ? buckets_ref[next_index] : nullptr;
            }
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return current_entry != other.current_entry || current_index != other.current_index;
        }

        std::pair<const K&, V&> operator*() const {
            if (current_entry) {
                return { current_entry->key, current_entry->value };
            } else {
                throw std::invalid_argument("Invalid iterator dereference");
            }
        }
    };

    Iterator begin() const {
        size_t first_index = 0;
        while (first_index < buckets.size() && !buckets[first_index]) {
            ++first_index;
        }
        return Iterator(first_index, first_index < buckets.size() ? buckets[first_index] : nullptr, buckets);
    }

    Iterator end() const {
        return Iterator(buckets.size(), nullptr, buckets);
    }
};

template <typename K, typename V>
void HashTable<K, V>::add(const K& key, const V& value) {
    if (!exists(key)) {
        size_t index = hash_function(key) % 15;
        Entry* new_entry = new Entry(key, value);
        if (!buckets[index]) {
            buckets[index] = new_entry;
        } else {
            Entry* current = buckets[index];
            while (current->next) {
                current = current->next;
            }
            current->next = new_entry;
        }
    } else {
        throw std::invalid_argument("Key already exists in the hash table");
    }
}

template <typename K, typename V>
bool HashTable<K, V>::exists(const K& key) const {
    size_t index = hash_function(key) % 15;
    Entry* current = buckets[index];
    while (current) {
        if (current->key == key) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template <typename K, typename V>
V& HashTable<K, V>::operator[](const K& key) {
    if (exists(key)) {
        size_t index = hash_function(key) % 15;
        Entry* current = buckets[index];
        while (current->key != key) {
            current = current->next;
        }
        return current->value;
    } else {
        throw std::invalid_argument("Key does not exist in the hash table");
    }
}
