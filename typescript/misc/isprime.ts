// A prime is a number bigger than 1 that only 1 and the number itself divide
// without a remainder.

export function isPrime(n: number): boolean {
  // no number you can divide n by without leaving a remainder other than 1
  // and n itself
  if (n < 2) {
    return false;
  }
  if (n === 2 || n === 3) {
    return true;
  }
  if (n % 2 === 0) {
    return false;
  }

  for (let i = 3; i * i <= n; i += 2) {
    if (n % i === 0) {
      return false;
    }
  }

  return true;
}

export function countPrimes(n: number): number {
  let count = 0;
  for (let i = 2; i <= n; i++) {
    if (isPrime(i)) {
      count++;
    }
  }
  return count;
}

export function getPrimes(n: number): number[] {
  const res: number[] = [];
  for (let i = 2; i <= n; i++) {
    if (isPrime(i)) {
      res.push(i);
    }
  }
  return res;
}
