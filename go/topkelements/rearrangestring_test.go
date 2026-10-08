package topkelements

import "testing"

func Test_rearrangeString(t *testing.T) {
	tests := []struct {
		name string // description of this test case
		// Named input parameters for target function.
		str  string
		want string
	}{
		// TODO: Add test cases.
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := rearrangeString(tt.str)
			// TODO: update the condition below to compare got with tt.want.
			if true {
				t.Errorf("rearrangeString() = %v, want %v", got, tt.want)
			}
		})
	}
}
