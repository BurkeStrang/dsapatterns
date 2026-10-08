namespace DsaPatterns.TwoHeaps;

internal class SlidingWindowMedian
{
    // max-heap holding the smaller half of the window
    private readonly PriorityQueue<int, int> maxHeap = Shared.NewMaxHeap();

    // min-heap holding the larger half of the window
    private readonly PriorityQueue<int, int> minHeap = new();

    internal double[] FindSlidingWindowMedian(int[] nums, int k)
    {
        double[] result = new double[nums.Length - k + 1];
        maxHeap.Clear();
        minHeap.Clear();

        for (int i = 0; i < nums.Length; i++)
        {
            if (maxHeap.Count == 0 || maxHeap.Peek() >= nums[i])
            {
                maxHeap.Enqueue(nums[i], nums[i]);
            }
            else
            {
                minHeap.Enqueue(nums[i], nums[i]);
            }

            RebalanceHeaps();

            if (i - k + 1 >= 0)
            {
                if (maxHeap.Count == minHeap.Count)
                {
                    result[i - k + 1] = (maxHeap.Peek() + minHeap.Peek()) / 2.0;
                }
                else
                {
                    result[i - k + 1] = maxHeap.Peek();
                }

                int elementToBeRemoved = nums[i - k + 1];
                if (elementToBeRemoved <= maxHeap.Peek())
                {
                    maxHeap.Remove(elementToBeRemoved, out _, out _);
                }
                else
                {
                    minHeap.Remove(elementToBeRemoved, out _, out _);
                }

                RebalanceHeaps();
            }
        }

        return result;
    }

    private void RebalanceHeaps()
    {
        if (maxHeap.Count > minHeap.Count + 1)
        {
            int top = maxHeap.Dequeue();
            minHeap.Enqueue(top, top);
        }
        else if (maxHeap.Count < minHeap.Count)
        {
            int top = minHeap.Dequeue();
            maxHeap.Enqueue(top, top);
        }
    }
}
