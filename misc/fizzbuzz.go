package misc

import "strconv"

func fizzBuzz(n int) []string {
	res := make([]string, 0, n+1)
	for i := 1; i <= n; i++ {
		switch {
		case i%15 == 0:
			res = append(res, "FizzBuzz")
		case i%5 == 0:
			res = append(res, "Buzz")
		case i%3 == 0:
			res = append(res, "Fizz")
		default:
			res = append(res, strconv.Itoa(i))
		}
	}
	return res
}
