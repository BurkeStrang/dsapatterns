// Given a set of positive numbers,
// partition the set into two subsets with minimum difference between their
// subset sums.
//
// Example 1:
// Input: {1, 2, 3, 9}
// Output: 3
// Explanation: We can partition the given set into two subsets where minimum
// absolute difference
// between the sum of numbers is '3'. Following are the two subsets: {1, 2, 3} &
// {9}.
//
// Example 2:
// Input: {1, 2, 7, 1, 5}
// Output: 0
// Explanation: We can partition the given set into two subsets where minimum
// absolute difference
// between the sum of number is '0'. Following are the two subsets: {1, 2, 5} &
// {7, 1}.
//
// Example 3:
// Input: {1, 3, 100, 4}
// Output: 92
// Explanation: We can partition the given set into two subsets where minimum
// absolute difference
// between the sum of numbers is '92'. Here are the two subsets: {1, 3, 4} &
// {100}.

export function canPartitionMinRecursive(
  num: number[],
  currentIndex: number,
  sum1: number,
  sum2: number,
): number {
  // Base check
  if (currentIndex === num.length) {
    return Math.abs(sum1 - sum2);
  }

  // Recursive call after including the number at the currentIndex in the
  // first set
  const diff1 = canPartitionMinRecursive(
    num,
    currentIndex + 1,
    sum1 + num[currentIndex],
    sum2,
  );

  // Recursive call after including the number at the currentIndex in the
  // second set
  const diff2 = canPartitionMinRecursive(
    num,
    currentIndex + 1,
    sum1,
    sum2 + num[currentIndex],
  );

  return Math.min(diff1, diff2);
}

export function canPartitionMin(num: number[]): number {
  return canPartitionMinRecursive(num, 0, 0, 0);
}
