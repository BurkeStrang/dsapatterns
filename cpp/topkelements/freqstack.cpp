#include <optional>
#include <queue>
#include <tuple>
#include <unordered_map>

// Design a class that simulates a Stack data structure,
// implementing the following two operations:
//
// push(int num): Pushes the number ‘num’ on the stack.
// pop(): Returns the most frequent number in the stack.
// If there is a tie, return the number which was pushed later.
//
// Example:
// After following push operations: push(1), push(2), push(3), push(2), push(1),
// push(2), push(5)
// 1. pop() should return 2, as it is the most frequent number
// 2. Next pop() should return 1
// 3. Next pop() should return 2

class FrequencyStack
{
  public:
    void push(int num)
    {
        int frequency = ++frequency_map[num];
        max_heap.push({frequency, sequence_number, num});
        sequence_number++;
    }

    // pop returns the most frequent number, or nothing once the stack is
    // empty
    std::optional<int> pop()
    {
        if (max_heap.empty())
        {
            return std::nullopt;
        }
        int num = std::get<2>(max_heap.top());
        max_heap.pop();

        // decrement the frequency or remove if this is the last number
        if (frequency_map[num] > 1)
        {
            frequency_map[num]--;
        }
        else
        {
            frequency_map.erase(num);
        }

        return num;
    }

  private:
    // one push onto the stack: (frequency, sequence number, number). Tuples
    // compare field by field, so the max heap gives the most frequent number,
    // and among equally frequent ones the one pushed last.
    using Element = std::tuple<int, int, int>;

    int sequence_number = 0;
    std::priority_queue<Element> max_heap;
    std::unordered_map<int, int> frequency_map;
};
