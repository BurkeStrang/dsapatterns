package bitwisexor

import "testing"

func Test_bitwiseComplement(t *testing.T) {
	tests := []struct {
		name string
		num  int
		want int
	}{
		// number: 5 (binary 101) -> complement: 2 (binary 010)
		{name: "Example 1", num: 5, want: 2},
		// number: 7 (binary 111) -> complement: 0 (binary 000)
		{name: "Example 2", num: 7, want: 0},
		// number: 10 (binary 1010) -> complement: 5 (binary 0101)
		{name: "Example 3", num: 10, want: 5},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := bitwiseComplement(tt.num)
			if got != tt.want {
				t.Errorf("bitwiseComplement() = %v, want %v", got, tt.want)
			}
		})
	}
}

