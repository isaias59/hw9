#pragma once
#include <iostream>
#include <array>

using namespace std;

template<typename K, typename V, size_t N>
class MapArray {
private:
    std::array<std::pair<K, V>, N> elements;

public:
    void insert(const K& key, const V& value) {
        for (auto& element : elements) {
            if (element.first == key) {
                std::cout << "Key already exists." << std::endl;
                return;
            }
        }
        for (auto& element : elements) {
            if (element.first == K()) {
                element.first = key;
                element.second = value;
                return;
            }
        }
        std::cout << "Map is full." << std::endl;
    }

    void display() const {
        for (const auto& element : elements) {
            if (element.first != K()) {
                std::cout << element.first << ": " << element.second << std::endl;
            }
        }
    }
};

