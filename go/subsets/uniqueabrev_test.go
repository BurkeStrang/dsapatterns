package subsets

import "testing"

func Test_generateGeneralizedAbbreviation(t *testing.T) {
	tests := []struct {
		name string // description of this test case
		// Named input parameters for target function.
		word string
		want []string
	}{
		{
			name: "word",
			word: "word",
			want: []string{
				"word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4",
			},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := generateGeneralizedAbbreviation(tt.word)
			if !equalUnorderdedStringSlices(got, tt.want) {
				t.Errorf("generateGeneralizedAbbreviation() = %v, want %v", got, tt.want)
			}
		})
	}
}

func equalUnorderdedStringSlices(a, b []string) bool {
	if len(a) != len(b) {
		return false
	}
	m := make(map[string]int)
	for _, s := range a {
		m[s]++
	}
	for _, s := range b {
		if m[s] == 0 {
			return false
		}
		m[s]--
	}
	return true
}
