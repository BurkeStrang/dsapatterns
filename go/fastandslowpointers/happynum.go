package fastandslowpointers

func isHappy(num int) bool {
	slow := num
	fast := num
	for {
		slow = findSquareSum(slow)                // move one step
		fast = findSquareSum(findSquareSum(fast)) // move two steps
		if slow == fast {
			break // found the cycle
		}
	}

	return slow == 1 // see if the cycle is stuck on the number '1'
}

func findSquareSum(num int) int {
	sum := 0
	var digit int
	for num > 0 {
		digit = num % 10
		sum += digit * digit
		num /= 10
	}
	return sum
}
