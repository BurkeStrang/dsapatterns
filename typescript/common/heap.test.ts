import { describe, expect, test } from "vitest";

import { Heap } from "./heap.ts";

// drain pops every item, so the order they come out in can be checked.
function drain<T>(heap: Heap<T>): T[] {
  const out: T[] = [];
  for (let item = heap.pop(); item !== undefined; item = heap.pop()) {
    out.push(item);
  }
  return out;
}

describe("Heap", () => {
  test("min heap pops the smallest first", () => {
    const heap = new Heap<number>((a, b) => a < b, [5, 1, 4, 1, 3]);
    expect(heap.size).toBe(5);
    expect(heap.peek()).toBe(1);
    expect(drain(heap)).toEqual([1, 1, 3, 4, 5]);
  });

  test("max heap pops the largest first", () => {
    const heap = new Heap<number>((a, b) => a > b, [2, 9, 7]);
    expect(drain(heap)).toEqual([9, 7, 2]);
  });

  test("empty heap", () => {
    const heap = new Heap<number>((a, b) => a < b);
    expect(heap.peek()).toBeUndefined();
    expect(heap.pop()).toBeUndefined();
  });

  test("remove from the middle", () => {
    const heap = new Heap<number>((a, b) => a < b, [8, 3, 6, 1, 9, 4]);
    expect(heap.remove(6)).toBe(true);
    expect(heap.remove(7)).toBe(false);
    expect(drain(heap)).toEqual([1, 3, 4, 8, 9]);
  });
});
