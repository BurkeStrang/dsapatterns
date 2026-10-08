package slidingwindow

import "testing"

func Test_findSubstring(t *testing.T) {
	tests := []struct {
		name    string
		str     string
		pattern string
		want    string
	}{
		{
			name:    "Example 1",
			str:     "aabdec",
			pattern: "abc",
			want:    "abdec",
		},
		{
			name:    "Example 2",
			str:     "aabdec",
			pattern: "abac",
			want:    "aabdec",
		},
		{
			name:    "Example 3",
			str:     "abdbca",
			pattern: "abc",
			want:    "bca",
		},
		{
			name:    "Example 4",
			str:     "adcad",
			pattern: "abc",
			want:    "",
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findSubstring(tt.str, tt.pattern)
			if got != tt.want {
				t.Errorf("findSubstring() = %v, want %v", got, tt.want)
			}
		})
	}
}
