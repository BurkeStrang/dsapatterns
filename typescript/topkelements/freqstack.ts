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

import { Heap } from "../common/heap.ts";

// one push onto the stack
interface Element {
  frequency: number;
  sequenceNumber: number;
  num: number;
}

export class FrequencyStack {
  private sequenceNumber = 0;
  // the max heap gives the most frequent number, and among equally frequent
  // ones the one pushed last
  private readonly maxHeap = new Heap<Element>(
    (a, b) =>
      a.frequency > b.frequency ||
      (a.frequency === b.frequency && a.sequenceNumber > b.sequenceNumber),
  );
  private readonly frequencyMap = new Map<number, number>();

  push(num: number): void {
    const frequency = (this.frequencyMap.get(num) ?? 0) + 1;
    this.frequencyMap.set(num, frequency);
    this.maxHeap.push({ frequency, sequenceNumber: this.sequenceNumber, num });
    this.sequenceNumber++;
  }

  // pop returns the most frequent number, or null once the stack is empty
  pop(): number | null {
    const top = this.maxHeap.pop();
    if (top === undefined) {
      return null;
    }
    const num = top.num;

    // decrement the frequency or remove if this is the last number
    const frequency = this.frequencyMap.get(num) ?? 0;
    if (frequency > 1) {
      this.frequencyMap.set(num, frequency - 1);
    } else {
      this.frequencyMap.delete(num);
    }
    return num;
  }
}
