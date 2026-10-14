#include "searchsuggestionsystem.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<std::string> products;
        std::string search_word;
        std::vector<std::vector<std::string>> want;
    };
    std::vector<test> tests = {
        {"Test Case 1",
         {"mobile", "mouse", "moneypot", "monitor", "mousepad"},
         "mouse",
         {{"mobile", "moneypot", "monitor"},
          {"mobile", "moneypot", "monitor"},
          {"mouse", "mousepad"},
          {"mouse", "mousepad"},
          {"mouse", "mousepad"}}},
        {"Test Case 2",
         {"havana"},
         "havana",
         std::vector<std::vector<std::string>>(6, {"havana"})},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("suggested_products()",
                 suggested_products(tt.products, tt.search_word), tt.want);
    }
    return t::done();
}
