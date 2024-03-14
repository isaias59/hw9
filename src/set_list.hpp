#ifndef SET_LIST_HPP
#define SET_LIST_HPP

#include <algorithm>
#include <functional>
#include <iterator>
#include <memory>
#include <ranges>

template <typename T>
class SetList {
    struct ListNode {
        T data;
        std::shared_ptr<ListNode> next;
        ListNode(T data, std::shared_ptr<ListNode> next = nullptr) : data(data), next(next) {}
    };

public:
    class ListIterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        explicit ListIterator(std::shared_ptr<ListNode> ptr = nullptr) : ptr(ptr) {}

        ListIterator& operator++() {
            if (ptr) ptr = ptr->next;
            return *this;
        }

        ListIterator operator++(int) {
            ListIterator tmp = *this;
            ++(*this);
            return tmp;
        }

        reference operator*() const {
            return ptr->data;
        }

        pointer operator->() const {
            return &ptr->data;
        }

        bool operator==(const ListIterator& other) const {
            return ptr == other.ptr;
        }

        bool operator!=(const ListIterator& other) const {
            return !(*this == other);
        }

    private:
        std::shared_ptr<ListNode> ptr;
    };

    SetList() = default;

    template <std::ranges::input_range Rng>
    explicit SetList(Rng&& rng) {
        std::ranges::for_each(std::forward<Rng>(rng), [&](const T& value) { insert(value); });
    }

    ListIterator begin() {
        return ListIterator(head);
    }

    ListIterator end() {
        return ListIterator(nullptr);
    }

    bool contains(const T& value) {
        for (auto it = begin(); it != end(); ++it) {
            if (*it == value) return true;
        }
        return false;
    }

    ListIterator insert(T value) {
        std::shared_ptr<ListNode> node = std::make_shared<ListNode>(value);
        if (!head || head->data > value) {
            node->next = head;
            head = node;
        }
        else {
            auto prev = head;
            auto curr = head->next;
            while (curr && curr->data < value) {
                prev = curr;
                curr = curr->next;
            }
            if (!curr || curr->data > value) {
                node->next = curr;
                prev->next = node;
            }
        }
        return ListIterator(node);
    }

private:
    std::shared_ptr<ListNode> head = nullptr;
};

#endif
