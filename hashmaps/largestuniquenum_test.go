package hashmaps

import "testing"

func Test_largestUniqueNumber(t *testing.T) {
	tests := []struct {
		name string
		A    []int
		want int
	}{
		{
			name: "Example 1",
			A:    []int{5, 7, 3, 7, 5, 8},
			want: 8,
		},
		{
			name: "Example 2",
			A:    []int{1, 2, 3, 2, 1, 4, 4},
			want: 3,
		},
		{
			name: "Example 3",
			A:    []int{9, 9, 8, 8, 7, 7},
			want: -1,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := largestUniqueNumber(tt.A)
			if got != tt.want {
				t.Errorf("largestUniqueNumber() = %v, want %v", got, tt.want)
			}
		})
	}
}
