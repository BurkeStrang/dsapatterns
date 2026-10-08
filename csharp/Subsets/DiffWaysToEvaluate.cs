namespace DsaPatterns.Subsets;

// Given an expression containing digits and operations (+, -, *),
// find all possible ways in which the expression can be evaluated
// by grouping the numbers and operators using parentheses.
//
// Example 1:
// Input: "1+2*3"
// Output: 7, 9
// Explanation:
//   1+(2*3) => 7
//   (1+2)*3 => 9
//
// Example 2:
// Input: "2*3-4-5"
// Output: 8, -12, 7, -7, -3
// Explanation:
//   2*(3-(4-5)) => 8
//   2*(3-4-5) => -12
//   2*3-(4-5) => 7
//   2*(3-4)-5 => -7
//   (2*3)-4-5 => -3

internal static class DiffWaysToEvaluate
{
    internal static List<int> DiffWaysToEvaluateExpression(string input)
    {
        List<int> result = [];
        // base case: if the input string is a number, parse and add it to
        // output.
        if (
            !input.Contains('+')
            && !input.Contains('-')
            && !input.Contains('*')
        )
        {
            result.Add(int.Parse(input));
        }
        else
        {
            for (int i = 0; i < input.Length; i++)
            {
                char chr = input[i];
                if (!char.IsDigit(chr))
                {
                    // break the equation here into two parts and make
                    // recursively calls
                    List<int> leftParts = DiffWaysToEvaluateExpression(
                        input[..i]
                    );
                    List<int> rightParts = DiffWaysToEvaluateExpression(
                        input[(i + 1)..]
                    );
                    foreach (int part1 in leftParts)
                    {
                        foreach (int part2 in rightParts)
                        {
                            switch (chr)
                            {
                                case '+':
                                    result.Add(part1 + part2);
                                    break;
                                case '-':
                                    result.Add(part1 - part2);
                                    break;
                                case '*':
                                    result.Add(part1 * part2);
                                    break;
                            }
                        }
                    }
                }
            }
        }

        return result;
    }
}
