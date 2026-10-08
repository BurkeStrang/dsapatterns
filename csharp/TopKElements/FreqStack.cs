namespace DsaPatterns.TopKElements;

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

internal class FreqStack
{
    // max-heap of numbers ordered by frequency, then by how recently they were
    // pushed (their sequence number)
    private readonly PriorityQueue<
        int,
        (int Frequency, int SequenceNumber)
    > maxHeap = new(
        Comparer<(int Frequency, int SequenceNumber)>.Create(
            (a, b) => b.CompareTo(a)
        )
    );
    private readonly Dictionary<int, int> frequencyMap = [];
    private int sequenceNumber;

    internal void Push(int num)
    {
        frequencyMap[num] = frequencyMap.GetValueOrDefault(num) + 1;
        maxHeap.Enqueue(num, (frequencyMap[num], sequenceNumber));
        sequenceNumber++;
    }

    internal int Pop()
    {
        int num = maxHeap.Dequeue();

        if (frequencyMap[num] > 1)
        {
            frequencyMap[num]--;
        }
        else
        {
            frequencyMap.Remove(num);
        }

        return num;
    }
}
