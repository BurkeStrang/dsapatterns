#include <vector>

// Given a stack, sort it using only stack operations (push and pop).
// You can use an additional temporary stack,
//
// but you may not copy the elements into any other data structure (such as an
// array).
// The values in the stack are to be sorted in descending order, with the
// largest elements on top.
//
// Example 1. Input: [34, 3, 31, 98, 92, 23]
// Output: [3, 23, 31, 34, 92, 98]
//
// Example 2. Input: [4, 3, 2, 10, 12, 1, 5, 6]
// Output: [1, 2, 3, 4, 5, 6, 10, 12]
//
// Example 3. Input: [20, 10, -5, -1]
// Output: [-5, -1, 10, 20]

// A vector is the stack here: push and pop work on its end, so the last
// element is the top.
std::vector<int> sort_stack(std::vector<int> input)
{
    // Create a temporary stack to hold sorted elements
    std::vector<int> tmp_stack;

    // Pop the top element from the input stack
    while (!input.empty())
    {
        int tmp = input.back();
        input.pop_back();

        // Compare the element with the top element of the temporary stack
        // and move elements from tmp_stack to input stack until the correct
        // position is found
        while (!tmp_stack.empty() && tmp_stack.back() > tmp)
        {
            input.push_back(tmp_stack.back());
            tmp_stack.pop_back();
        }

        // Push the current element to the temporary stack in the correct
        // sorted position
        tmp_stack.push_back(tmp);
    }

    return tmp_stack; // Return the sorted stack
}
