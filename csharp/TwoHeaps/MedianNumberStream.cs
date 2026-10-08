namespace DsaPatterns.TwoHeaps;

internal class MedianNumberStream
{
    // max-heap holding the smaller half of the numbers
    private readonly PriorityQueue<int, int> maxHeap = Shared.NewMaxHeap();

    // min-heap holding the larger half of the numbers
    private readonly PriorityQueue<int, int> minHeap = new();

    internal void InsertNum(int num)
    {
        if (maxHeap.Count == 0 || maxHeap.Peek() >= num)
        {
            maxHeap.Enqueue(num, num);
        }
        else
        {
            minHeap.Enqueue(num, num);
        }

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

    internal double FindMedian()
    {
        if (maxHeap.Count == minHeap.Count)
        {
            return (maxHeap.Peek() / 2.0) + (minHeap.Peek() / 2.0);
        }

        return maxHeap.Peek();
    }
}
