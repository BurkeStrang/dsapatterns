package hashmaps

import "testing"

func Test_longestPalindrome(t *testing.T) {
	tests := []struct {
		name string
		s    string
		want int
	}{
		{
			name: "applepie",
			s:    "applepie",
			want: 5,
		},
		{
			name: "aabbcc",
			s:    "aabbcc",
			want: 6,
		},
		{
			name: "bananas",
			s:    "bananas",
			want: 5,
		},
		{
			name: "single character",
			s:    "a",
			want: 1,
		},
		{
			name: "all unique",
			s:    "abcdef",
			want: 1,
		},
		{
			name: "all pairs",
			s:    "aabb",
			want: 4,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := longestPalindrome(tt.s)
			if got != tt.want {
				t.Errorf("longestPalindrome() = %v, want %v", got, tt.want)
			}
		})
	}
}
