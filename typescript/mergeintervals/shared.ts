// Helpers shared by the merge intervals problems.

export interface Interval {
  start: number;
  end: number;
}

// intervals turns [start, end] pairs into intervals, to keep the test tables
// short.
export function intervals(pairs: [number, number][]): Interval[] {
  return pairs.map(([start, end]) => ({ start, end }));
}
