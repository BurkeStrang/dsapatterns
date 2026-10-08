package subsets

import "testing"

func Test_generateValidParentheses(t *testing.T) {
	tests := []struct {
		name string
		num  int
		want []string
	}{
		{
			"example 1",
			2,
			[]string{"(())", "()()"},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := generateValidParentheses(tt.num)
			if !equalStringSlices(got, tt.want) {
				t.Errorf("generateValidParentheses() = %v, want %v", got, tt.want)
			}
		})
	}
}

func equalStringSlices(a, b []string) bool {
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
