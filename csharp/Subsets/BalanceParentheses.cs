namespace DsaPatterns.Subsets;

internal record struct ParenthesesString(
    string Str,
    int OpenCount, // open parentheses count
    int CloseCount // close parentheses count
);

internal static class BalanceParentheses
{
    internal static List<string> GenerateValidParentheses(int num)
    {
        List<string> result = [];
        Queue<ParenthesesString> queue = new();
        queue.Enqueue(new ParenthesesString("", 0, 0));
        while (queue.Count > 0)
        {
            ParenthesesString ps = queue.Dequeue();
            // if we've reached the maximum number of open and close
            // parentheses, add to result
            if (ps.OpenCount == num && ps.CloseCount == num)
            {
                result.Add(ps.Str);
            }
            else
            {
                // if we can add an open parentheses, add it
                if (ps.OpenCount < num)
                {
                    queue.Enqueue(
                        new ParenthesesString(
                            ps.Str + "(",
                            ps.OpenCount + 1,
                            ps.CloseCount
                        )
                    );
                }

                // if we can add a close parentheses, add it
                if (ps.OpenCount > ps.CloseCount)
                {
                    queue.Enqueue(
                        new ParenthesesString(
                            ps.Str + ")",
                            ps.OpenCount,
                            ps.CloseCount + 1
                        )
                    );
                }
            }
        }

        return result;
    }
}
