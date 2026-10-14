// Given two strings containing backspaces (identified by the character ‘#’),
// check if the two strings are equal.
//
// Example 1:
//
// Input: str1="xy#z", str2="xzz#"
// Output: true
// Explanation: After applying backspaces the strings become "xz" and "xz"
// respectively.
// Example 2:
//
// Input: str1="xy#z", str2="xyz#"
// Output: false
// Explanation: After applying backspaces the strings become "xz" and "xy"
// respectively.
// Example 3:
//
// Input: str1="xp#", str2="xyz##"
// Output: true
// Explanation: After applying backspaces the strings become "x" and "x"
// respectively.
// In "xyz##", the first '#' removes the character 'z' and the second '#'
// removes the character 'y'.
// Example 4:
//
// Input: str1="xywrrmp", str2="xywrrmu#p"
// Output: true
// Explanation: After applying backspaces the strings become "xywrrmp" and
// "xywrrmp" respectively.
// Constraints:
//
// 1 <= str1.length, str2.length <= 200
// str1 and str2 only contain lowercase letters and '#' characters.

// getNextValidCharIndex returns the index of the next character that is not
// deleted by a backspace, looking from index towards the start; -1 once we
// have gone past the start
export function getNextValidCharIndex(s: string, index: number): number {
  let backspaceCount = 0;
  while (index >= 0) {
    if (s[index] === "#") {
      // found a backspace character
      backspaceCount++;
    } else if (backspaceCount > 0) {
      // a non-backspace character
      backspaceCount--;
    } else {
      break;
    }
    index--; // skip a backspace or a valid character
  }
  return index;
}

export function compare(str1: string, str2: string): boolean {
  // the next character to look at in each string, counting from the end
  let index1 = str1.length - 1;
  let index2 = str2.length - 1;
  while (index1 >= 0 || index2 >= 0) {
    const i1 = getNextValidCharIndex(str1, index1);
    const i2 = getNextValidCharIndex(str2, index2);
    if (i1 < 0 && i2 < 0) {
      return true; // reached the end of both the strings
    }
    if (i1 < 0 || i2 < 0) {
      return false; // reached the end of one of the strings
    }
    if (str1[i1] !== str2[i2]) {
      return false; // check if the characters are equal
    }
    index1 = i1 - 1;
    index2 = i2 - 1;
  }
  return true;
}
