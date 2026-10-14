// Given a string,
// find if its letters can be rearranged in such a way that no two same
// characters come next to each other.
//
// Example 1:
// Input: "aappp"
// Output: "papap"
// Explanation: In "papap", none of the repeating characters come next to each
// other.
//
// Example 2:
// Input: "Programming"
// Output: "rgmrgmPiano" or "gmringmrPoa" or "gmrPagimnor", etc.
// Explanation: None of the repeating characters come next to each other.
//
// Example 3:
// Input: "aapa"
// Output: ""
// Explanation: In all arrangements of "aapa", atleast two 'a' will come
// together e.g., "apaa", "paaa".

import { Heap } from "../common/heap.ts";
import { countLetters, moreFrequentFirst } from "./shared.ts";

export function rearrangeString(s: string): string {
  const maxHeap = new Heap<[number, string]>(moreFrequentFirst);
  for (const [chr, count] of countLetters(s)) {
    maxHeap.push([count, chr]);
  }

  let result = "";
  // the character used in the previous step, kept out of the heap for one
  // step so that it can't be picked twice in a row
  let previous: [number, string] | null = null;
  for (let top = maxHeap.pop(); top !== undefined; top = maxHeap.pop()) {
    const [count, currentChar] = top;

    // the previous character can be added back to the heap now, if there is
    // any of it left
    if (previous !== null && previous[0] > 0) {
      maxHeap.push(previous);
    }

    // append the current character to the result string and decrement its
    // count
    result += currentChar;
    previous = [count - 1, currentChar];
  }

  // if we were successful in appending all the characters to the result
  // string, return it
  return result.length === s.length ? result : "";
}
