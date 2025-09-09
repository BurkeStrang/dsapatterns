package slidingwindow

import "testing"

func Test_findMinSubArray(t *testing.T) {
	tests := []struct {
		name string // description of this test case
		// Named input parameters for target function.
		S    int
		arr  []int
		want int
	}{
		// TODO: Add test cases.
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findMinSubArray(tt.S, tt.arr)
			// TODO: update the condition below to compare got with tt.want.
			if true {
				t.Errorf("findMinSubArray() = %v, want %v", got, tt.want)
			}
		})
	}
}

