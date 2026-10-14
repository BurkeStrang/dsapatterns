// Singly linked lists, as used by the linked list patterns.
//
// Nodes are plain pointers, like the Go code. new_node keeps every node it
// makes in a pool that lives until the program exits, so solutions can link
// and unlink nodes freely (cycles included) without anyone deleting them.
#pragma once

#include <deque>
#include <vector>

struct ListNode
{
    int value;
    ListNode *next = nullptr;
};

// new_node makes a node that stays valid until the program exits.
inline ListNode *new_node(int value, ListNode *next = nullptr)
{
    static std::deque<ListNode> pool;
    pool.push_back(ListNode{value, next});
    return &pool.back();
}

// build_list makes a linked list holding the given values, in order.
inline ListNode *build_list(const std::vector<int> &values)
{
    ListNode *head = nullptr;
    for (auto it = values.rbegin(); it != values.rend(); it++)
    {
        head = new_node(*it, head);
    }
    return head;
}

// build_nodes makes the nodes of a list and returns all of them, so a test
// can point a node somewhere else, for example to make a cycle.
inline std::vector<ListNode *> build_nodes(const std::vector<int> &values)
{
    std::vector<ListNode *> nodes;
    ListNode *head = build_list(values);
    for (ListNode *node = head; node != nullptr; node = node->next)
    {
        nodes.push_back(node);
    }
    return nodes;
}

// list_values collects the values of a list, so two lists are easy to
// compare. It stops after 1000 nodes in case the list has a cycle.
inline std::vector<int> list_values(const ListNode *head)
{
    std::vector<int> values;
    for (const ListNode *node = head; node != nullptr && values.size() < 1000;
         node = node->next)
    {
        values.push_back(node->value);
    }
    return values;
}
