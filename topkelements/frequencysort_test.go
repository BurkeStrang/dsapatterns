package topkelements

import "testing"

func Test_sortCharactersByFrequency(t *testing.T) {
	tests := []struct {
		name string
		s    string
		want string
	}{
		{name: "Example 1", s: "Programming", want: "rrmmggainPo"},
		{name: "Example 2", s: "abcbab", want: "bbbaac"},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := sortCharacterByFrequency(tt.s)
			if !validFrequencySort(tt.s, got) {
				t.Errorf("sortCharactersByFrequency() = %v, want %v", got, tt.want)
			}
		})
	}
}

func validFrequencySort(input, output string) bool {
	if len(input) != len(output) {
		return false
	}

	freq := map[rune]int{}
	for _, r := range input {
		freq[r]++
	}

	prevFreq := int(^uint(0) >> 1) // max int

	i := 0
	for i < len(output) {
		r := rune(output[i])
		count := 0

		for i < len(output) && rune(output[i]) == r {
			count++
			i++
		}

		if freq[r] != count {
			return false
		}

		if count > prevFreq {
			return false
		}

		prevFreq = count
	}

	return true
}
