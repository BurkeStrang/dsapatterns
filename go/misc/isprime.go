package misc

func isPrime(n int) bool {
	// no number you can divide n by without leaving a remainder other than 1
	// and n itself
	if n < 2 {
		return false
	}
	if n == 2 || n == 3 {
		return true
	}
	if n%2 == 0 {
		return false
	}
	for i := 3; i*i <= n; i += 2 {
		if n%i == 0 {
			return false
		}
	}
	return true
}

func countPrimes(n int) int {
	count := 0
	for i := 2; i <= n; i++ {
		if isPrime(i) {
			count++
		}
	}
	return count
}

func getPrimes(n int) []int {
	res := []int{}
	for i := 2; i <= n; i++ {
		if isPrime(i) {
			res = append(res, i)
		}
	}
	return res
}
