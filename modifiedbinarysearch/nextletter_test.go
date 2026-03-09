package modifiedbinarysearch

import "testing"

func Test_searchNextLetter(t *testing.T) {
	tests := []struct {
		name string // description of this test case
		// Named input parameters for target function.
		letters []string
		key     string
		want    string
	}{
		{name: "key in middle of array", letters: []string{"a", "c", "f", "h"}, key: "f", want: "h"},
		{name: "key before first element", letters: []string{"a", "c", "f", "h"}, key: "b", want: "c"},
		{name: "key is smallest element", letters: []string{"a", "c", "f", "h"}, key: "a", want: "c"},
		{name: "key is largest element - wraps around", letters: []string{"a", "c", "f", "h"}, key: "h", want: "a"},
		{name: "key larger than all - wraps around", letters: []string{"a", "c", "f", "h"}, key: "z", want: "a"},
		{name: "key smaller than all elements", letters: []string{"c", "f", "j"}, key: "a", want: "c"},
		{name: "key between two adjacent elements", letters: []string{"a", "c", "f", "h"}, key: "g", want: "h"},
		{name: "single element - wraps around", letters: []string{"m"}, key: "m", want: "m"},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := searchNextLetter(tt.letters, tt.key)
			if got != tt.want {
				t.Errorf("searchNextLetter() = %v, want %v", got, tt.want)
			}
		})
	}
}
