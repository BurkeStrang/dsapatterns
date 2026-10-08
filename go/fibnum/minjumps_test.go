package fibnum

import "testing"

func Test_countMinJumps(t *testing.T) {
	tests := []struct {
		name string // description of this test case
		// Named input parameters for target function.
		jumps []int
		want  int
	}{
		// TODO: Add test cases.
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := countMinJumps(tt.jumps)
			// TODO: update the condition below to compare got with tt.want.
			if true {
				t.Errorf("countMinJumps() = %v, want %v", got, tt.want)
			}
		})
	}
}
