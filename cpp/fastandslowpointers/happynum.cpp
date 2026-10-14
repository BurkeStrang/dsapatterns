// Any number will be called a happy number if, after repeatedly replacing it
// with a number equal to the sum of the square of all of its digits, leads us
// to the number 1. All other (not-happy) numbers will never reach 1. Instead,
// they will be stuck in a cycle of numbers that does not include 1.

int find_square_sum(int num)
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

bool is_happy(int num)
{
    int slow = num;
    int fast = num;
    while (true)
    {
        slow = find_square_sum(slow);                  // move one step
        fast = find_square_sum(find_square_sum(fast)); // move two steps
        if (slow == fast)
        {
            break; // found the cycle
        }
    }
    return slow == 1; // see if the cycle is stuck on the number '1'
}
