namespace DsaPatterns.KWayMerge;

public class MergeKSortedListTests
{
    public static TheoryData<string, int[][], int[]> Cases =>
        new()
        {
            {
                "Example 1",
                [
                    [2, 6, 8],
                    [3, 6, 7],
                    [1, 3, 4],
                ],
                [1, 2, 3, 3, 4, 6, 6, 7, 8]
            },
            {
                "Example 2",
                [
                    [5, 8, 9],
                    [1, 7],
                ],
                [1, 5, 7, 8, 9]
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void Merge(string name, int[][] lists, int[] want)
    {
        ListNode?[] input = lists.Select(ToList).ToArray();

        ListNode? merged = MergeKSortedList.Merge(input);

        List<int> got = [];
        for (ListNode? node = merged; node != null; node = node.Next)
        {
            got.Add(node.Val);
        }

        Assert.True(
            got.SequenceEqual(want),
            $"{name}: got {Shared.Format(got)}, want {Shared.Format(want)}"
        );
    }

    private static ListNode? ToList(int[] vals)
    {
        ListNode? head = null;
        for (int i = vals.Length - 1; i >= 0; i--)
        {
            head = new ListNode(vals[i], head);
        }

        return head;
    }
}
