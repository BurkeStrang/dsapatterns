#pragma once

#include <format>
#include <string>

struct Interval
{
    int start;
    int end;

    bool operator==(const Interval &) const = default;
};

inline std::string to_string(const Interval &interval)
{
    return std::format("[{}, {}]", interval.start, interval.end);
}
