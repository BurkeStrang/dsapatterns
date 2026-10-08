package slidingwindow

import "testing"

func Test_findStringAnagrams(t *testing.T) {
	tests := []struct {
		name string // description of this test case
		// Named input parameters for target function.
		str     string
		pattern string
		want    []int
	}{
		{
			name:    "Example 1",
			str:     "ppqp",
			pattern: "pq",
			want:    []int{1, 2},
		},
		{
			name:    "Example 2",
			str:     "abbcabc",
			pattern: "abc",
			want:    []int{2, 3, 4},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findStringAnagrams(tt.str, tt.pattern)
			if !equalIntSlices(got, tt.want) {
				t.Errorf("findStringAnagrams() = %v, want %v", got, tt.want)
			}
		})
	}
}

func equalIntSlices(a, b []int) bool {
	if len(a) != len(b) {
		return false
	}
	for i := range a {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}
