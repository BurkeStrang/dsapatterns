// JavaScript has no heap (priority queue) of its own, so the heap patterns
// use this one.
//
// Heap is a binary heap ordered by the 'less' function given to it: the item
// that is less than every other item is on top. Pass (a, b) => a < b for a
// min heap of numbers and (a, b) => a > b for a max heap.

export class Heap<T> {
  private readonly items: T[] = [];
  private readonly less: (a: T, b: T) => boolean;

  constructor(less: (a: T, b: T) => boolean, items: T[] = []) {
    this.less = less;
    for (const item of items) {
      this.push(item);
    }
  }

  get size(): number {
    return this.items.length;
  }

  // peek returns the top item without removing it, or undefined if the
  // heap is empty.
  peek(): T | undefined {
    return this.items.at(0);
  }

  push(item: T): void {
    this.items.push(item);
    this.up(this.items.length - 1);
  }

  // pop removes and returns the top item, or undefined if the heap is
  // empty.
  pop(): T | undefined {
    const top = this.items.at(0);
    const last = this.items.pop();
    if (this.items.length > 0 && last !== undefined) {
      this.items[0] = last;
      this.down(0);
    }
    return top;
  }

  // remove takes one copy of item (compared with ===) out of the heap, from
  // anywhere in it, and reports whether it was there.
  remove(item: T): boolean {
    const index = this.items.indexOf(item);
    if (index === -1) {
      return false;
    }
    const last = this.items.pop();
    if (index < this.items.length && last !== undefined) {
      this.items[index] = last;
      this.down(index);
      this.up(index);
    }
    return true;
  }

  // toArray returns the items in no particular order.
  toArray(): T[] {
    return [...this.items];
  }

  private up(index: number): void {
    while (index > 0) {
      const parent = Math.floor((index - 1) / 2);
      if (!this.less(this.items[index], this.items[parent])) {
        return;
      }
      this.swap(index, parent);
      index = parent;
    }
  }

  private down(index: number): void {
    for (;;) {
      const left = 2 * index + 1;
      const right = left + 1;
      let smallest = index;
      if (
        left < this.items.length &&
        this.less(this.items[left], this.items[smallest])
      ) {
        smallest = left;
      }
      if (
        right < this.items.length &&
        this.less(this.items[right], this.items[smallest])
      ) {
        smallest = right;
      }
      if (smallest === index) {
        return;
      }
      this.swap(index, smallest);
      index = smallest;
    }
  }

  private swap(i: number, j: number): void {
    [this.items[i], this.items[j]] = [this.items[j], this.items[i]];
  }
}
