// Helpers shared by the subsets tests.

// compareLists orders two number lists element by element, the shorter one
// first when one is the start of the other.
export function compareLists(a: number[], b: number[]): number {
  for (let i = 0; i < Math.min(a.length, b.length); i++) {
    if (a[i] !== b[i]) {
      return a[i] - b[i];
    }
  }
  return a.length - b.length;
}

// sortedSubsets sorts each subset and then the list of subsets, so that two
// lists holding the same subsets in a different order compare equal.
export function sortedSubsets(subsets: number[][]): number[][] {
  return subsets
    .map((subset) => [...subset].sort((a, b) => a - b))
    .sort(compareLists);
}
