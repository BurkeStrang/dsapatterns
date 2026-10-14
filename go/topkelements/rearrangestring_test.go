package topkelements

import "testing"

func Test_rearrangeString(t *testing.T) {
	tests := []struct {
		name     string
		str      string
		possible bool
	}{
		{name: "Example 1", str: "aappp", possible: true},
		{name: "Example 2", str: "Programming", possible: true},
		{name: "Example 3", str: "aapa", possible: false},
		{name: "Single character", str: "a", possible: true},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := rearrangeString(tt.str)
			if !tt.possible {
				if got != "" {
					t.Errorf("rearrangeString() = %q, want %q", got, "")
				}
				return
			}
			// no two equal letters next to each other is the same as every
			// pair of equal letters being at least 2 apart
			if !validRearrangement(tt.str, got, 2) {
				t.Errorf("rearrangeString() = %q, not a valid arrangement of %q", got, tt.str)
			}
		})
	}
}
