#ifndef MAP_ARRAY_HPP
#define MAP_ARRAY_HPP

#include <algorithm>
#include <cstddef> 
#include <iterator>
#include <vector>

template <typename Key, typename Value>
class MapArray {
public:
    class ArrayIterator {
    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = std::pair<Key, Value>;
        using difference_type = std::ptrdiff_t;
        using pointer = std::pair<Key, Value>*;
        using reference = std::pair<Key, Value>&;

        explicit ArrayIterator(pointer ptr = nullptr) : ptr(ptr) {}

        
        ArrayIterator& operator++() {
            ++ptr;
            return *this;
        }

        ArrayIterator operator++(int) {
            ArrayIterator tmp = *this;
            ++(*this);
            return tmp;
        }

        ArrayIterator& operator--() {
            --ptr;
            return *this;
        }

        ArrayIterator operator--(int) {
            ArrayIterator tmp = *this;
            --(*this);
            return tmp;
        }

        
        ArrayIterator& operator+=(difference_type n) {
            ptr += n;
            return *this;
        }

        ArrayIterator& operator-=(difference_type n) {
            ptr -= n;
            return *this;
        }

        friend ArrayIterator operator+(ArrayIterator it, difference_type n) {
            return ArrayIterator(it.ptr + n);
        }

        friend ArrayIterator operator-(ArrayIterator it, difference_type n) {
            return ArrayIterator(it.ptr - n);
        }

        difference_type operator-(const ArrayIterator& other) const {
            return ptr - other.ptr;
        }

        
        bool operator<(const ArrayIterator& other) const { return ptr < other.ptr; }
        bool operator>(const ArrayIterator& other) const { return ptr > other.ptr; }
        bool operator<=(const ArrayIterator& other) const { return ptr <= other.ptr; }
        bool operator>=(const ArrayIterator& other) const { return ptr >= other.ptr; }

        
        reference operator*() const { return *ptr; }
        pointer operator->() const { return ptr; }

        
        reference operator[](difference_type n) const { return *(ptr + n); }

        
        bool operator==(const ArrayIterator& other) const { return ptr == other.ptr; }
        bool operator!=(const ArrayIterator& other) const { return ptr != other.ptr; }

    private:
        pointer ptr;
    };

    MapArray() = default;

    
    ArrayIterator begin() { return ArrayIterator(data.data()); }
    ArrayIterator end() { return ArrayIterator(data.data() + data.size()); }

    
    Value& operator[](const Key& key) {
        auto it = std::find_if(begin(), end(), [&key](const auto& pair) { return pair.first == key; });
        if (it == end()) {
            data.push_back(std::make_pair(key, Value{}));
            return data.back().second;
        }
        else {
            return it->second;
        }
    }

private:
    std::vector<std::pair<Key, Value>> data;
};

#endif 
