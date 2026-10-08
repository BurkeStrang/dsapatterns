namespace DsaPatterns.FastAndSlowPointers;

internal static class HappyNum
{
    internal static bool IsHappy(int num)
    {
        int slow = num;
        int fast = num;
        do
        {
            slow = FindSquareSum(slow); // move one step
            fast = FindSquareSum(FindSquareSum(fast)); // move two steps
        } while (slow != fast); // found the cycle

        return slow == 1; // see if the cycle is stuck on the number '1'
    }

    private static int FindSquareSum(int num)
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
}
