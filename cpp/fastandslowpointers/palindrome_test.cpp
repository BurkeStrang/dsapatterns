#include "palindrome.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> head;
        bool want;
    };
    std::vector<test> tests = {
        {"odd length palindrome", {2, 4, 6, 4, 2}, true},
        {"not a palindrome", {2, 4, 6, 4, 2, 2}, false},
        {"empty list", {}, true},
        {"single node", {1}, true},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        ListNode *head = build_list(tt.head);
        t::check("is_palindrome()", is_palindrome(head), tt.want);
        // the list must be put back the way it was
        t::check("list after is_palindrome()", list_values(head), tt.head);
    }
    return t::done();
}
