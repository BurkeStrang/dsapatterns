#include "searchadd.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *const *add;
        int add_len;
        const char *word;
        bool want;
    } tests[] = {
        {"SearchNode 'c.t'", STRS("cat", "dog"), "c.t", true},
        {"SearchNode 'd..g'", STRS("cat", "dog"), "d..g", false},
        {"SearchNode 'h.llo'", STRS("hello"), "h.llo", true},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        TrieNode *root = trie_node_new();
        for (int w = 0; w < tt->add_len; w++)
        {
            add_word(root, tt->add[w]);
        }
        bool got = search_node(root, tt->word);
        t_check_bool("search_node()", got, tt->want);
        trie_free(root);
    }
    return t_done();
}
