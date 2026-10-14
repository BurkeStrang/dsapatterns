package topkelements

import (
	"slices"
	"testing"
)

func Test_reorganizeString(t *testing.T) {
	tests := []struct {
		name     string
		str      string
		k        int
		possible bool
	}{
		{name: "Example 1", str: "mmpp", k: 2, possible: true},
		{name: "Example 2", str: "Programming", k: 3, possible: true},
		{name: "Example 3", str: "aab", k: 2, possible: true},
		{name: "Example 4", str: "aappa", k: 3, possible: false},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := reorganizeString(tt.str, tt.k)
			if !tt.possible {
				if got != "" {
					t.Errorf("reorganizeString() = %q, want %q", got, "")
				}
				return
			}
			// letters with the same count can come out in any order, so check
			// the result is a valid arrangement instead of one exact string
			if !validRearrangement(tt.str, got, tt.k) {
				t.Errorf("reorganizeString() = %q, not a valid arrangement of %q", got, tt.str)
			}
		})
	}
}

// validRearrangement reports whether output uses exactly the letters of input
// and keeps every pair of equal letters at least k apart.
func validRearrangement(input, output string, k int) bool {
	in, out := []byte(input), []byte(output)
	slices.Sort(in)
	slices.Sort(out)
	if !slices.Equal(in, out) {
		return false
	}

	lastSeen := map[byte]int{}
	for i := 0; i < len(output); i++ {
		if prev, ok := lastSeen[output[i]]; ok && i-prev < k {
			return false
		}
		lastSeen[output[i]] = i
	}
	return true
}
