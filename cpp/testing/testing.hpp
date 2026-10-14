// Header-only helpers for table-driven tests.
//
// A test file includes its solution, loops over a table of cases, and reports
// through these helpers:
//
//   t::run(name)            start a test case
//   t::check(label, got, want)
//                           report a failure if got != want
//   t::check_near(label, got, want)
//                           the same for floating point values
//   t::errorf(fmt, args...) report any other failure for the current case
//   t::done()               print the result; return it from main
//
// Failure messages print values with t::str, which understands numbers,
// strings, std::vector, std::optional and std::pair, nested to any depth, and
// any type that has a `std::string to_string(const T &)` function.
#pragma once

#include <cmath>
#include <cstdio>
#include <format>
#include <optional>
#include <source_location>
#include <string>
#include <string_view>
#include <type_traits>
#include <utility>
#include <vector>

namespace t
{

// ---------------------------------------------------------------------------
// Formatting
// ---------------------------------------------------------------------------

template <typename T> std::string str(const T &value);

namespace detail
{

template <typename T> struct is_vector : std::false_type
{
};
template <typename T> struct is_vector<std::vector<T>> : std::true_type
{
};

template <typename T> struct is_optional : std::false_type
{
};
template <typename T> struct is_optional<std::optional<T>> : std::true_type
{
};

template <typename T> struct is_pair : std::false_type
{
};
template <typename A, typename B>
struct is_pair<std::pair<A, B>> : std::true_type
{
};

} // namespace detail

// str turns a value into text such as "[1, 2, 3]" for failure messages.
template <typename T> std::string str(const T &value)
{
    if constexpr (std::is_same_v<T, bool>)
    {
        return value ? "true" : "false";
    }
    else if constexpr (std::is_same_v<T, char>)
    {
        return std::format("'{}'", value);
    }
    else if constexpr (std::is_arithmetic_v<T>)
    {
        return std::format("{}", value);
    }
    else if constexpr (std::is_convertible_v<T, std::string_view>)
    {
        return std::format("\"{}\"", std::string_view(value));
    }
    else if constexpr (detail::is_vector<T>::value)
    {
        std::string out = "[";
        for (std::size_t i = 0; i < value.size(); i++)
        {
            out += (i == 0 ? "" : ", ") + str(value[i]);
        }
        return out + "]";
    }
    else if constexpr (detail::is_optional<T>::value)
    {
        return value ? str(*value) : "nullopt";
    }
    else if constexpr (detail::is_pair<T>::value)
    {
        return "(" + str(value.first) + ", " + str(value.second) + ")";
    }
    else if constexpr (requires { to_string(value); })
    {
        // a type of this repo, such as an interval, that has its own
        // to_string function
        return to_string(value);
    }
    else
    {
        static_assert(sizeof(T) == 0, "t::str has no overload for this type");
    }
}

// ---------------------------------------------------------------------------
// Running cases and reporting failures
// ---------------------------------------------------------------------------

namespace detail
{

inline std::string case_name;
inline int case_count = 0;
inline int failure_count = 0;
inline bool case_failed = false;

inline void fail(const std::string &message, std::source_location where)
{
    if (!case_failed)
    {
        case_failed = true;
        failure_count++;
    }
    std::printf("--- FAIL: %s (%s:%u)\n    %s\n", case_name.c_str(),
                where.file_name(), where.line(), message.c_str());
}

} // namespace detail

// run starts a new test case; later failures are reported under its name.
inline void run(std::string_view name)
{
    detail::case_name = name;
    detail::case_count++;
    detail::case_failed = false;
}

// errorf reports a failure for the current case, like t.Errorf in Go.
// It is a struct so the caller's file and line can be picked up after the
// variadic arguments.
template <typename... Args> struct errorf
{
    errorf(std::format_string<Args...> fmt, Args &&...args,
           std::source_location where = std::source_location::current())
    {
        detail::fail(std::format(fmt, std::forward<Args>(args)...), where);
    }
};
template <typename... Args>
errorf(std::format_string<Args...>, Args &&...) -> errorf<Args...>;

// check reports a failure if got != want, printing both values.
template <typename Got, typename Want>
bool check(std::string_view label, const Got &got, const Want &want,
           std::source_location where = std::source_location::current())
{
    if (got == want)
    {
        return true;
    }
    detail::fail(std::format("{} = {}, want {}", label, str(got), str(want)),
                 where);
    return false;
}

namespace detail
{

constexpr double epsilon = 1e-9;

inline bool near(double a, double b)
{
    return std::fabs(a - b) < epsilon;
}

inline bool near(const std::vector<double> &a, const std::vector<double> &b)
{
    if (a.size() != b.size())
    {
        return false;
    }
    for (std::size_t i = 0; i < a.size(); i++)
    {
        if (!near(a[i], b[i]))
        {
            return false;
        }
    }
    return true;
}

} // namespace detail

// check_near is check for a double or a vector of doubles; values that
// differ by less than 1e-9 count as equal.
template <typename T>
bool check_near(std::string_view label, const T &got, const T &want,
                std::source_location where = std::source_location::current())
{
    if (detail::near(got, want))
    {
        return true;
    }
    detail::fail(std::format("{} = {}, want {}", label, str(got), str(want)),
                 where);
    return false;
}

// done prints the summary and returns the exit code for main.
inline int done()
{
    if (detail::failure_count > 0)
    {
        std::printf("FAIL: %d of %d cases failed\n", detail::failure_count,
                    detail::case_count);
        return 1;
    }
    std::printf("PASS: %d cases\n", detail::case_count);
    return 0;
}

} // namespace t
