// There is a dictionary containing words from an alien language
// for which we don't know the ordering of the letters.
// Given a list of strings words from the alien language's dictionary.
// All strings in words are sorted lexicographically by the rules of this new
// language.
// Return a string of the unique letters in the new alien language
// sorted in lexicographically increasing order by the new language's rules.
// It is given that the input is a valid dictionary and there exists an ordering
// among its letters.
//
// Example 1:
// Input: Words: ["ba", "bc", "ac", "cab"]
// Output: bac
// Explanation: Given that the words are sorted lexicographically by the rules
// of the alien language, so
// from the given words we can conclude the following ordering among its
// characters:
// 1. From "ba" and "bc", we can conclude that 'a' comes before 'c'.
// 2. From "bc" and "ac", we can conclude that 'b' comes before 'a'
// From the above two points, we can conclude that the correct character order
// is: "bac"
//
// Example 2:
// Input: Words: ["cab", "aaa", "aab"]
// Output: cab
// Explanation: From the given words we can conclude the following ordering
// among its characters:
// 1. From "cab" and "aaa", we can conclude that 'c' comes before 'a'.
// 2. From "aaa" and "aab", we can conclude that 'a' comes before 'b'
// From the above two points, we can conclude that the correct character order
// is: "cab"
//
// Example 3:
// Input: Words: ["ywx", "wz", "xww", "xz", "zyy", "zwz"]
// Output: ywxz
// Explanation: From the given words we can conclude the following ordering
// among its characters:
// 1. From "ywx" and "wz", we can conclude that 'y' comes before 'w'.
// 2. From "wz" and "xww", we can conclude that 'w' comes before 'x'.
// 3. From "xww" and "xz", we can conclude that 'w' comes before 'z'
// 4. From "xz" and "zyy", we can conclude that 'x' comes before 'z'
// 5. From "zyy" and "zwz", we can conclude that 'y' comes before 'w'
//
// From the above five points, we can conclude that the correct character order
// is: "ywxz"
// Constraints:
// 1 <= words.length <= 100
// 1 <= words[i].length <= 100
// words[i] consists of only lowercase English letters.

export function findAlienOrder(words: string[]): string {
  if (words.length === 0) {
    return "";
  }

  // a. Initialize the graph; a Map keeps the letters in the order they first
  // appear, so the sources are always visited in the same order
  const inDegree = new Map<string, number>();
  const graph = new Map<string, string[]>();
  for (const word of words) {
    for (const character of word) {
      if (!graph.has(character)) {
        graph.set(character, []);
        inDegree.set(character, 0);
      }
    }
  }

  // b. Build the graph
  for (let i = 0; i + 1 < words.length; i++) {
    // find ordering of characters from adjacent words
    const w1 = words[i];
    const w2 = words[i + 1];
    let foundDifference = false;
    for (let j = 0; j < Math.min(w1.length, w2.length); j++) {
      const parent = w1[j];
      const child = w2[j];
      if (parent !== child) {
        graph.get(parent)?.push(child);
        inDegree.set(child, (inDegree.get(child) ?? 0) + 1);
        foundDifference = true;
        break;
      }
    }

    // a word cannot come before one of its own prefixes: "abc" before "ab"
    // is not a valid dictionary, so no letter ordering can explain it
    if (!foundDifference && w1.length > w2.length) {
      return "";
    }
  }

  // c. Find all sources i.e., all vertices with 0 in-degrees
  const sources: string[] = [];
  for (const [letter, count] of inDegree) {
    if (count === 0) {
      sources.push(letter);
    }
  }

  // d. For each source, add it to the sortedOrder and subtract one from all
  // of its children's in-degrees if a child's in-degree becomes zero, add it
  // to sources queue
  let sortedOrder = "";
  // a for-of loop over an array also visits the items pushed onto it while
  // the loop runs, so the array works as the queue
  for (const vertex of sources) {
    sortedOrder += vertex;
    for (const child of graph.get(vertex) ?? []) {
      const degree = (inDegree.get(child) ?? 0) - 1;
      inDegree.set(child, degree);
      if (degree === 0) {
        sources.push(child);
      }
    }
  }

  // if sortedOrder doesn't contain all characters, there is a cyclic
  // dependency between characters, therefore, we will not be able to find
  // the correct ordering of the characters
  if (sortedOrder.length !== inDegree.size) {
    return "";
  }

  return sortedOrder;
}
