#include "common/map.h"

// Given a string s,
// return the maximum number of unique substrings that the given string can be
// split into.
// You can split string s into any list of non-empty substrings,
// where the concatenation of the substrings forms the original string.
// However, you must split the substrings such that all of them are unique.
// A substring is a contiguous sequence of characters within a string.
//
// Example 1:
// Input: s = "aab"
// Output: 2
// Explanation: Two possible ways to split the given string into maximum unique
// substrings are:
// ['a', 'ab'] & ['aa', 'b'], both have 2 substrings;
// hence the maximum number of unique substrings in
// which the given string can be split is 2.
//
// Example 2:
// Input: s = "abcabc"
// Output: 4
// Explanation: Four possible ways to split into maximum unique substrings are:
// ['a', 'b', 'c', 'abc'] & ['a', 'b', 'cab', 'c'] &  ['a', 'bca', 'b', 'c'] &
// ['abc', 'a', 'b', 'c'],
// all have 4 substrings.
//
// Constraints:
// 1 <= s.length <= 16
// s contains only lower case English letters.

// set holds the substrings used so far (StrMap used as a set).
int split_and_count
(
    const char *str,
    int start,
    StrMap *set
)
{
    int str_len = (int)strlen(str);
    if (start == str_len)
    {
        return set->len;
    }

    int count = 0;
    char *substr = malloc((size_t)str_len + 1);
    for (int i = start + 1; i <= str_len; i++)
    {
        memcpy(substr, str + start, (size_t)(i - start));
        substr[i - start] = '\0';
        if (!strmap_has(set, substr))
        {
            strmap_set(set, substr, 1);
            int found = split_and_count(str, i, set);
            if (found > count)
            {
                count = found;
            }
            strmap_remove(set, substr);
        }
    }
    free(substr);
    return count;
}

int max_unique_split
(
    const char *str
)
{
    StrMap set = {0};
    int count = split_and_count(str, 0, &set);
    strmap_free(&set);
    return count;
}
