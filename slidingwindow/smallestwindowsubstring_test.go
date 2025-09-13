package slidingwindow

import "testing"

func Test_findSubstring(t *testing.T) {
	tests := []struct {
		name string // description of this test case
		// Named input parameters for target function.
		str     string
		pattern string
		want    string
	}{
		// TODO: Add test cases.
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findSubstring(tt.str, tt.pattern)
			// TODO: update the condition below to compare got with tt.want.
			if true {
				t.Errorf("findSubstring() = %v, want %v", got, tt.want)
			}
		})
	}
}

