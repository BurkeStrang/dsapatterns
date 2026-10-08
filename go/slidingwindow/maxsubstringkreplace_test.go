package slidingwindow

import "testing"

func Test_maxLengthReplace(t *testing.T) {
	tests := []struct {
		name string
		str  string
		k    int
		want int
	}{
		{
			name: "Example 1",
			str:  "aabccbb",
			k:    2,
			want: 5,
		},
		{
			name: "Example 2",
			str:  "abbcb",
			k:    1,
			want: 4,
		},
		{
			name: "Example 3",
			str:  "abccde",
			k:    1,
			want: 3,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := maxLengthReplace(tt.str, tt.k)
			if got != tt.want {
				t.Errorf("maxLengthReplace() = %v, want %v", got, tt.want)
			}
		})
	}
}
