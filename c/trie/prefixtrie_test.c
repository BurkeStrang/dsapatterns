#include "prefixtrie.c"

#include "testing/testing.h"

static void test_search(void)
{
    struct test
    {
        const char *name;
        const char *word;
        bool want;
    } tests[] = {
        {"Search 'grape'", "grape", true},
        {"Search 'grapefruit'", "grapefruit", true},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        TrieNode *root = trie_node_new();
        insert(root, tt->word);
        bool got = search(root, tt->word);
        t_check_bool("search()", got, tt->want);
        trie_free(root);
    }
}

static void test_starts_with(void)
{
    struct test
    {
        const char *name;
        const char *prefix;
        const char *word;
        bool want;
    } tests[] = {
        {"StartsWith 'grap'", "grap", "grape", true},
        {"StartsWith 'gr'", "gr", "grape", true},
        {"StartsWith 'gra'", "gra", "grape", true},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        TrieNode *root = trie_node_new();
        insert(root, tt->word);
        bool got = starts_with(root, tt->prefix);
        t_check_bool("starts_with()", got, tt->want);
        trie_free(root);
    }
}

int main(void)
{
    test_search();
    test_starts_with();
    return t_done();
}
