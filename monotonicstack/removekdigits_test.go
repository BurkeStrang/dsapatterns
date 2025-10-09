package monotonicstack

import "testing"

func Test_removeKdigits(t *testing.T) {
	tests := []struct {
		name string
		num  string
		k    int
		want string
	}{
		{
			name: "Example 1",
			num:  "1432219",
			k:    3,
			want: "1219",
		},
		{
			name: "Example 2",
			num:  "10200",
			k:    1,
			want: "200",
		},
		{
			name: "Example 3",
			num:  "1901042",
			k:    4,
			want: "2",
		},
		{
			name: "Remove all digits",
			num:  "10",
			k:    2,
			want: "0",
		},
		{
			name: "Leading zeros after removal",
			num:  "100200",
			k:    1,
			want: "200",
		},
		{
			name: "No removal needed",
			num:  "12345",
			k:    0,
			want: "12345",
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := removeKdigits(tt.num, tt.k)
			if got != tt.want {
				t.Errorf("removeKdigits() = %v, want %v", got, tt.want)
			}
		})
	}
}

