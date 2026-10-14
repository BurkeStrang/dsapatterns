#include "minmeetingrooms.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<Meeting> meetings;
        int want;
    };
    std::vector<test> tests = {
        {"Example 1: overlapping meetings", {{1, 4}, {2, 5}, {7, 9}}, 2},
        {"Example 2: non-overlapping meetings", {{6, 7}, {2, 4}, {8, 12}}, 1},
        {"Example 3: overlapping meetings", {{1, 4}, {2, 3}, {3, 6}}, 2},
        {"Example 4: complex overlaps", {{4, 5}, {2, 3}, {2, 4}, {3, 5}}, 2},
    };
    for (test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_minimum_meeting_rooms()",
                 find_minimum_meeting_rooms(tt.meetings), tt.want);
    }
    return t::done();
}
