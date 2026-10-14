// Helpers shared by the top K elements problems.

// countLetters returns how many times each character appears in s.
export function countLetters(s: string): Map<string, number> {
  const counts = new Map<string, number>();
  for (const c of s) {
    counts.set(c, (counts.get(c) ?? 0) + 1);
  }
  return counts;
}

// moreFrequentFirst orders [frequency, letter] pairs for a max heap: the most
// frequent letter is on top, and among letters with the same frequency the
// earlier letter comes first, so the result is always the same
export function moreFrequentFirst(
  a: [number, string],
  b: [number, string],
): boolean {
  return a[0] > b[0] || (a[0] === b[0] && a[1] < b[1]);
}
