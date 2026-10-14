#include <sstream>
#include <string>
#include <vector>

// Given an absolute file path in a Unix-style file system,
// simplify it by converting ".." to the previous directory and removing any "."
// or multiple slashes.
// The resulting string should represent the shortest absolute path.
//
// Example 1
// Input: path = "/a//b////c/d//././/.."
// Expected Output: "/a/b/c"
// Explanation:
// Convert multiple slashes (//) into single slashes (/).
// "." refers to the current directory and is ignored.
// ".." moves up one directory, so "d" is removed.
// The simplified path is "/a/b/c".
//
// Example 2
// Input: path = "/../"
// Expected Output: "/"
// Explanation:
// ".." moves up one directory, but we are already at the root ("/"), so nothing
// happens.
// The final simplified path remains "/".
//
// Example 3
// Input: path = "/home//foo/"
// Expected Output: "/home/foo"
// Explanation:
// Convert multiple slashes (//) into single slashes (/).
// The final simplified path is "/home/foo".
//
// Constraints:
// 1 <= path.length <= 3000
// path consists of English letters, digits, period '.', slash '/' or '_'.
// path is a valid absolute Unix path.

std::string simplify_path(const std::string &path)
{
    // Create a stack to store the simplified path components
    std::vector<std::string> stack;

    // Split the input path string using '/' as a delimiter
    std::stringstream components(path);
    std::string p;
    while (std::getline(components, p, '/'))
    {
        if (p == "..")
        {
            // If the component is '..', pop the last component from the stack
            if (!stack.empty())
            {
                stack.pop_back();
            }
        }
        else if (!p.empty() && p != ".")
        {
            // If the component is not empty and not '.', push it onto the
            // stack
            stack.push_back(p);
        }
    }

    // Reconstruct the simplified path by joining components from the stack
    std::string result;
    for (const std::string &component : stack)
    {
        result += "/" + component;
    }
    return result.empty() ? "/" : result;
}
