#include "ransomnote.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::string ransom_note;
        std::string magazine;
        bool want;
    };
    std::vector<test> tests = {
        {"can construct hello from hellworld", "hello", "hellworld", true},
        {"can construct notes from stoned", "notes", "stoned", true},
        {"cannot construct apple from pale", "apple", "pale", false},
        {"exact match", "abc", "abc", true},
        {"not enough letters", "aabb", "ab", false},
        {"empty ransom note", "", "anything", true},
        {"empty magazine", "a", "", false},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("can_construct()", can_construct(tt.ransom_note, tt.magazine),
                 tt.want);
    }
    return t::done();
}
