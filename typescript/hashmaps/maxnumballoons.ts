// Given a string, determine the maximum number of times the word "balloon" can
// be formed using the characters from the string.
// Each character in the string can be used only once.
//
// Example 1:
// Input: "balloonballoon"
// Expected Output: 2
// Justification: The word "balloon" can be formed twice from the given string.
//
// Example 2:
// Input: "bbaall"
// Expected Output: 0
// Justification: The word "balloon" cannot be formed from the given string as
// we are missing the character 'o' twice.
//
// Example 3:
// Input: "balloonballoooon"
// Expected Output: 2
// Justification: The word "balloon" can be formed twice, even though there are
// extra 'o' characters.
//
// Constraints:
// 1 <= text.length <= 104
// text consists of lower case English letters only.

export function maxNumberOfBalloons(text: string): number {
  const freq = new Map<string, number>();
  for (const letter of text) {
    freq.set(letter, (freq.get(letter) ?? 0) + 1);
  }

  let minResult = text.length;
  for (const letter of "balon") {
    const count = freq.get(letter) ?? 0;
    if (letter === "l" || letter === "o") {
      minResult = Math.min(minResult, Math.floor(count / 2));
    } else {
      minResult = Math.min(minResult, count);
    }
  }
  return minResult;
}
