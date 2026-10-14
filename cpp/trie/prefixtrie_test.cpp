#include "prefixtrie.cpp"

#include "testing/testing.hpp"

#include <vector>

int main()
{
    struct test
    {
        std::string name;
        std::string inserted;
        std::string word;
        bool want_search;      // search(word)
        bool want_starts_with; // starts_with(word)
    };
    std::vector<test> tests = {
        {"grape", "grape", "grape", true, true},
        {"grapefruit", "grapefruit", "grapefruit", true, true},
        {"a prefix of a word", "grape", "grap", false, true},
        {"a shorter prefix", "grape", "gr", false, true},
        {"a longer word", "grape", "grapes", false, false},
        {"a different word", "grape", "gro", false, false},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        Trie trie;
        trie.insert(tt.inserted);
        t::check("search()", trie.search(tt.word), tt.want_search);
        t::check("starts_with()", trie.starts_with(tt.word),
                 tt.want_starts_with);
    }
    return t::done();
}
