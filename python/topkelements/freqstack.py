"""
Design a class that simulates a Stack data structure,
implementing the following two operations:

push(int num): Pushes the number ‘num’ on the stack.
pop(): Returns the most frequent number in the stack.
If there is a tie, return the number which was pushed later.

Example:
After following push operations: push(1), push(2), push(3), push(2), push(1),
push(2), push(5)
1. pop() should return 2, as it is the most frequent number
2. Next pop() should return 1
3. Next pop() should return 2
"""

import heapq
from collections import defaultdict


class FrequencyStack:
    def __init__(self) -> None:
        self.sequence_number = 0
        # one push onto the stack: (frequency, sequence number, number).
        # Tuples compare field by field, so a max heap gives the most frequent
        # number, and among equally frequent ones the one pushed last. heapq
        # only makes min-heaps, so the frequency and sequence number are
        # stored negated.
        self.max_heap: list[tuple[int, int, int]] = []
        self.frequency_map: defaultdict[int, int] = defaultdict(int)

    def push(self, num: int) -> None:
        self.frequency_map[num] += 1
        heapq.heappush(
            self.max_heap,
            (-self.frequency_map[num], -self.sequence_number, num),
        )
        self.sequence_number += 1

    def pop(self) -> int | None:
        """Returns the most frequent number, or None once the stack is
        empty."""
        if not self.max_heap:
            return None
        _, _, num = heapq.heappop(self.max_heap)

        # decrement the frequency or remove if this is the last number
        if self.frequency_map[num] > 1:
            self.frequency_map[num] -= 1
        else:
            del self.frequency_map[num]
        return num
