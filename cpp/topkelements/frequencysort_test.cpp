#include "frequencysort.cpp"

#include "testing/testing.hpp"

#include <climits>

// Characters with the same frequency may come out in any order, so check the
// shape of the output instead of comparing it with one fixed answer: each
// character sits in a single run as long as its frequency, and the runs never
// get longer.
bool valid_frequency_sort(const std::string &input, const std::string &output)
{
    if (input.size() != output.size())
    {
        return false;
    }

    std::unordered_map<char, int> freq;
    for (char c : input)
    {
        freq[c]++;
    }

    int prev_freq = INT_MAX;
    std::size_t i = 0;
    while (i < output.size())
    {
        char c = output[i];
        int count = 0;
        while (i < output.size() && output[i] == c)
        {
            count++;
            i++;
        }
        if (freq[c] != count || count > prev_freq)
        {
            return false;
        }
        prev_freq = count;
    }
    return true;
}

int main()
{
    struct test
    {
        std::string name;
        std::string s;
    };
    std::vector<test> tests = {
        {"Example 1", "Programming"},
        {"Example 2", "abcbab"},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        std::string got = sort_character_by_frequency(tt.s);
        if (!valid_frequency_sort(tt.s, got))
        {
            t::errorf("sort_character_by_frequency() = \"{}\"", got);
        }
    }
    return t::done();
}
