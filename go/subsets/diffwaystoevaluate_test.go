package subsets

import "testing"

func Test_diffWaysToEvaluateExpression(t *testing.T) {
	tests := []struct {
		name  string
		input string
		want  []int
	}{
		{
			name:  "parentheses addition",
			input: "2+3*2",
			want:  []int{8, 10},
		},
		{
			name:  "parentheses multiple",
			input: "2*4-3*5",
			want:  []int{-22, 10, -7, 10, 25},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := diffWaysToEvaluateExpression(tt.input)
			if !sliceEqual(got, tt.want) {
				t.Errorf("diffWaysToEvaluateExpression() = %v, want %v", got, tt.want)
			}
		})
	}
}

func sliceEqual(a, b []int) bool {
	if len(a) != len(b) {
		return false
	}
	for i := range a {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}
