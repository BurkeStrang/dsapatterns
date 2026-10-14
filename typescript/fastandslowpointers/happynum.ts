// Any number will be called a happy number if, after repeatedly replacing it
// with a number equal to the sum of the square of all of its digits, leads us
// to the number 1. All other (not-happy) numbers will never reach 1. Instead,
// they will be stuck in a cycle of numbers that does not include 1.

export function findSquareSum(num: number): number {
  let sum = 0;
  while (num > 0) {
    const digit = num % 10;
    sum += digit * digit;
    num = Math.floor(num / 10);
  }
  return sum;
}

export function isHappy(num: number): boolean {
  let slow = num;
  let fast = num;
  for (;;) {
    slow = findSquareSum(slow); // move one step
    fast = findSquareSum(findSquareSum(fast)); // move two steps
    if (slow === fast) {
      break; // found the cycle
    }
  }
  return slow === 1; // see if the cycle is stuck on the number '1'
}
