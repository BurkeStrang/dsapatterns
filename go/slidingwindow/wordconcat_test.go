package slidingwindow

import "testing"

func Test_findWordConcatenation(t *testing.T) {
	tests := []struct {
		name  string
		str   string
		words []string
		want  []int
	}{
		{
			name:  "Example 1",
			str:   "catfoxcat",
			words: []string{"cat", "fox"},
			want:  []int{0, 3},
		},
		{
			name:  "Example 2",
			str:   "catcatfoxfox",
			words: []string{"cat", "fox"},
			want:  []int{3},
		},
		{
			name:  "No match",
			str:   "abcdefg",
			words: []string{"hi", "jk"},
			want:  []int{},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findWordConcatenation(tt.str, tt.words)
			if !equalIntSlices(got, tt.want) {
				t.Errorf("findWordConcatenation() = %v, want %v", got, tt.want)
			}
		})
	}
}
