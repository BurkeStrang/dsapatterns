// Given a string and a number ‘K’,
// find if the string can be rearranged such that the same characters are at
// least ‘K’ distance apart from each other.
//
// Example 1:
// Input: "mmpp", K=2
// Output: "mpmp" or "pmpm"
// Explanation: All same characters are 2 distance apart.
//
// Example 2:
// Input: "Programming", K=3
// Output: "rgmPrgmiano" or "gmringmrPoa" or "gmrPagimnor" and a few more
// Explanation: All same characters are 3 distance apart.
//
// Example 3:
// Input: "aab", K=2
// Output: "aba"
// Explanation: All same characters are 2 distance apart.
//
// Example 4:
// Input: "aappa", K=3
// Output: ""
// Explanation: We cannot find an arrangement of the string where any two 'a'
// are 3 distance apart.

import { Heap } from "../common/heap.ts";
import { countLetters, moreFrequentFirst } from "./shared.ts";

export function reorganizeString(s: string, k: number): string {
  if (k <= 1) {
    return s;
  }

  const maxHeap = new Heap<[number, string]>(moreFrequentFirst);
  for (const [chr, count] of countLetters(s)) {
    maxHeap.push([count, chr]);
  }

  let result = "";
  const queue: [number, string][] = [];
  for (let top = maxHeap.pop(); top !== undefined; top = maxHeap.pop()) {
    const [frequency, letter] = top;
    // append the current character to the result string and decrement its
    // count
    result += letter;

    // the character has to wait for 'k' steps before it can be used again
    queue.push([frequency - 1, letter]);
    if (queue.length === k) {
      const entry = queue.shift();
      if (entry !== undefined && entry[0] > 0) {
        maxHeap.push(entry);
      }
    }
  }

  // if we were successful in appending all the characters to the result
  // string, return it
  return result.length === s.length ? result : "";
}
