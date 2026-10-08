namespace DsaPatterns.TreeBfs;

public class ConnectLevelOrderSiblingsTests
{
    // trees are given in level order, with null for a missing child; want is
    // the expected level order traversal using Next pointers
    public static TheoryData<string, int?[], int[][]> Cases =>
        new()
        {
            {
                "Example 1",
                [1, 2, 3, 4, 5, 6, 7],
                [
                    [1],
                    [2, 3],
                    [4, 5, 6, 7],
                ]
            },
            {
                "Example 2",
                [12, 7, 1, 9, null, 10, 5],
                [
                    [12],
                    [7, 1],
                    [9, 10, 5],
                ]
            },
            { "Empty tree", [], [] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void Connect(string name, int?[] tree, int[][] want)
    {
        TreeNode? gotRoot = ConnectLevelOrderSiblings.Connect(
            Shared.ToTree(tree)
        );

        List<List<int>> got = LevelOrderNext(gotRoot);
        Assert.True(
            Shared.Format2D(got) == Shared.Format2D(want),
            $"{name}: got {Shared.Format2D(got)}, "
                + $"want {Shared.Format2D(want)}"
        );
    }

    // LevelOrderNext traverses the tree using Next pointers and returns values
    // level by level.
    private static List<List<int>> LevelOrderNext(TreeNode? root)
    {
        List<List<int>> result = [];
        while (root != null)
        {
            List<int> level = [];
            TreeNode? curr = root;
            TreeNode? nextLevel = null;
            while (curr != null)
            {
                level.Add(curr.Val);
                nextLevel ??= curr.Left ?? curr.Right;
                curr = curr.Next;
            }

            result.Add(level);
            root = nextLevel;
        }

        return result;
    }
}
