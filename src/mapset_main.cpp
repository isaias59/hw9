#include "set_list.h"
#include "map_array.h"

using namespace std;

int main() {
    SetList<int> mySet;
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(10);
    mySet.display();

    MapArray<std::string, int, 5> myMap;
    myMap.insert("apple", 5);
    myMap.insert("banana", 10);
    myMap.insert("orange", 15);
    myMap.insert("apple", 20); 
    myMap.insert("grape", 25);
    myMap.display();

    return 0;
}

