package stack

import "testing"

func Test_decimalToBinary(t *testing.T) {
	tests := []struct {
		name string
		num  int
		want string
	}{
		{"Example 1", 2, "10"},
		{"Example 2", 7, "111"},
		{"Example 3", 18, "10010"},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := decimalToBinary(tt.num)
			if got != tt.want {
				t.Errorf("decimalToBinary() = %v, want %v", got, tt.want)
			}
		})
	}
}

