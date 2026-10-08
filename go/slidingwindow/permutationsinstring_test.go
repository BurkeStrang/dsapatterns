package slidingwindow

import "testing"

func Test_findPermutation(t *testing.T) {
	tests := []struct {
		name    string
		str     string
		pattern string
		want    bool
	}{
		{
			name:    "Example 1",
			str:     "oidbcaf",
			pattern: "abc",
			want:    true,
		},
		{
			name:    "Example 2",
			str:     "odicf",
			pattern: "dc",
			want:    false,
		},
		{
			name:    "Example 3",
			str:     "bcdxabcdy",
			pattern: "bcdyabcdx",
			want:    true,
		},
		{
			name:    "Example 4",
			str:     "aaacb",
			pattern: "abc",
			want:    true,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findPermutation(tt.str, tt.pattern)
			if got != tt.want {
				t.Errorf("findPermutation() = %v, want %v", got, tt.want)
			}
		})
	}
}
