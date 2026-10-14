// Example 1:
// Input: ['a', 'c', 'f', 'h'], key = 'f'
// Output: 'h'

export function searchNextLetter(letters: string[], key: string): string {
  const n = letters.length;
  let start = 0;
  let end = n - 1;
  while (start <= end) {
    const mid = start + Math.floor((end - start) / 2);
    if (key < letters[mid]) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }

  // since the loop is running until 'start <= end', so at the end of the
  // while loop, 'start === end+1'; if there is no bigger letter it is 'n',
  // which wraps around to the first letter
  return letters[start % n];
}
