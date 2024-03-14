#pragma once
#include <list>
#include <algorithm>
#include <iostream>


using namespace std;
template<typename T>
class SetList {
private:
    std::list<T> elements;

public:
    void insert(const T& element) {
        if (std::find(elements.begin(), elements.end(), element) == elements.end()) {
            elements.push_back(element);
        }
    }

    void display() const {
        for (const auto& element : elements) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
};
