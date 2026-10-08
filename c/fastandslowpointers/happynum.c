#include <stdbool.h>

int find_square_sum
(
    int num
)
{
    int sum = 0;
    while (num > 0)
    {
        int digit = num % 10;
        sum += digit * digit;
        num /= 10;
    }
    return sum;
}

bool is_happy
(
    int num
)
{
    int slow = num;
    int fast = num;
    do
    {
        slow = find_square_sum(slow);                  // move one step
        fast = find_square_sum(find_square_sum(fast)); // move two steps
    } while (slow != fast); // found the cycle

    return slow == 1; // see if the cycle is stuck on the number '1'
}
