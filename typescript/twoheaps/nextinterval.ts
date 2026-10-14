// Given an array of intervals, find the next interval of each interval. In a
// list of intervals, for an interval 'i' its next interval 'j' will have the
// smallest 'start' greater than or equal to the 'end' of 'i'.
//
// Write a function to return an array containing indices of the next interval
// of each input interval. If there is no next interval of a given interval,
// return -1. It is given that none of the intervals have the same start
// point.

import { Heap } from "../common/heap.ts";

export interface Interval {
  start: number;
  end: number;
}

// one end of an interval: the start or end time, and the interval's index
type Point = [number, number];

// laterFirst orders points for a max heap: the latest time on top, and the
// higher index first when the times are equal
function laterFirst(a: Point, b: Point): boolean {
  return a[0] > b[0] || (a[0] === b[0] && a[1] > b[1]);
}

export function findNextInterval(intervals: Interval[]): number[] {
  const maxStartHeap = new Heap<Point>(laterFirst);
  const maxEndHeap = new Heap<Point>(laterFirst);
  const result = new Array<number>(intervals.length).fill(-1); // Default to -1

  // Initialize heaps
  intervals.forEach((interval, i) => {
    maxStartHeap.push([interval.start, i]);
    maxEndHeap.push([interval.end, i]);
  });

  // Go through the intervals from the highest end to the lowest and find the
  // next interval of each
  for (let top = maxEndHeap.pop(); top !== undefined; top = maxEndHeap.pop()) {
    const [topEnd, endIndex] = top;

    // find the interval that has the closest 'start'; the last one popped
    // here is the one with the smallest start that is still >= the end
    let topStart: Point | undefined;
    let next = maxStartHeap.peek();
    while (next !== undefined && next[0] >= topEnd) {
      topStart = maxStartHeap.pop();
      next = maxStartHeap.peek();
    }

    if (topStart !== undefined) {
      result[endIndex] = topStart[1];
      // put the interval back as it could be the next interval of other
      // intervals
      maxStartHeap.push(topStart);
    }
  }

  return result;
}
