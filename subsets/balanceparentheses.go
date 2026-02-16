package subsets

type ParenthesesString struct {
	Str        string
	OpenCount  int // open parentheses count
	CloseCount int // close parentheses count
}

func NewParenthesesString(str string, openCount, closeCount int) *ParenthesesString {
	return &ParenthesesString{Str: str, OpenCount: openCount, CloseCount: closeCount}
}

func generateValidParentheses(num int) []string {
	result := []string{}
	queue := []*ParenthesesString{}
	queue = append(queue, NewParenthesesString("", 0, 0))

	for len(queue) > 0 {
		ps := queue[0]
		queue = queue[1:]

		// if we've reached the maximum number of open and close parentheses, add to result
		if ps.OpenCount == num && ps.CloseCount == num {
			result = append(result, ps.Str)
		} else {
			if ps.OpenCount < num { // if we can add an open parentheses, add it
				queue = append(queue, NewParenthesesString(ps.Str+"(", ps.OpenCount+1, ps.CloseCount))
			}

			if ps.OpenCount > ps.CloseCount { // if we can add a close parentheses, add it
				queue = append(queue, NewParenthesesString(ps.Str+")", ps.OpenCount, ps.CloseCount+1))
			}
		}
	}

	return result
}
