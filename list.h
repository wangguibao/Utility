/**
 * @file list.h
 * @author wangguibao(wang_guibao@163.com)
 * @date 2021/08/29 16:58
 * @brief Template functions for creating and traversing lists
 *
 **/
#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <vector>
#include <functional>
template<class T> struct Node {
public:
    Node(T val): value(val), next(nullptr){}

public:
    T value;
    Node* next;
};

/*
 * create_list
 * @brief Create a singly linked list from a set of elements
 *
 * @vec input vec
 *
 * @return a pointer to newly created list
 */
template<typename T>
Node<T>* create_list(const std::vector<T>& vec) {
    if (vec.empty()) {
        return nullptr;
    }

    Node<T>* head = nullptr;
    Node<T>* cur = nullptr;
    for (auto v: vec) {
        auto* ele = new Node<T>(v);
        ele->next = nullptr;

        if (head == nullptr) {
            head = ele;
            cur = ele;
        } else {
            cur->next = ele;
            cur = ele;
        }
    }

    return head;
}

/*
 * list_traverse
 * @brief Traverse a given list. Call func on each node
 *
 * @param list: list head
 * @param func: list traverse function
 *
 * @return void
 */
template<typename T>
void list_traverse(const Node<T>* list, std::function<void(T)> func) {
    auto p = list;
    while (p) {
        func(p->value);
        p = p->next;
    }
}

/*
 * list_destroy
 * @brief destroy a list
 *
 * @param list: list head
 *
 * @return void
 */
template<typename T>
void list_destroy(const Node<T>* list) {
    auto p = list;

    while (p) {
        auto next = p->next;
        delete p;
        p = next;
    }
}

/*
 * list_reverse
 * @brief reverse a singly-linked list, returning the new list head
 *
 * @param list: list head
 *
 * @return a pointer to the new list head
 */
template<typename T>
Node<T>* list_reverse(Node<T>* list) {
    Node<T>* prev = nullptr;
    Node<T>* cur = list;

    while (cur) {
        Node<T>* temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }

    return prev;
}

// Test case
#if 0
void print_value(int value) {
    std::cout << value << std::endl;
}

int main()
{
    std::vector<int> vec;

    for (int i = 0; i < 10; ++i) {
        vec.push_back(i);
    }

    auto list = create_list(vec);
    std::function<void(int)> traverse_func = print_value;

    std::cout << "Original list:" << std::endl;
    list_traverse(list, traverse_func);

    std::cout << "After reversal:" << std::endl;
    auto new_head = list_reverse(list);
    list_traverse(new_head, traverse_func);

    list_destroy(new_head);
    return 0;
}
#endif // 0

#endif // LIST_H_INCLUDED
/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
