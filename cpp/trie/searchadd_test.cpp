#include "searchadd.cpp"

#include "testing/testing.hpp"

#include <string>
#include <vector>

int main()
{
    struct test
    {
        std::string name;
        std::vector<std::string> add;
        std::string word;
        bool want;
    };
    std::vector<test> tests = {
        {"SearchNode 'c.t'", {"cat", "dog"}, "c.t", true},
        {"SearchNode 'd..g'", {"cat", "dog"}, "d..g", false},
        {"SearchNode 'h.llo'", {"hello"}, "h.llo", true},
        {"SearchNode '...'", {"cat", "dog"}, "...", true},
        {"SearchNode 'do'", {"cat", "dog"}, "do", false},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        Trie trie;
        for (const std::string &word : tt.add)
        {
            trie.add_word(word);
        }
        t::check("search_node()", trie.search_node(tt.word), tt.want);
    }
    return t::done();
}
