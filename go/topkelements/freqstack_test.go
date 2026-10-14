package topkelements

import (
	"slices"
	"testing"
)

func TestSolution_PushPop(t *testing.T) {
	tests := []struct {
		name   string
		pushes []int
		want   []int
	}{
		// 2 is the most frequent; then 1 and 2 are tied and 1 was pushed last;
		// then 2; after that every number left was pushed once, and the latest
		// of those comes out first
		{name: "Example", pushes: []int{1, 2, 3, 2, 1, 2, 5}, want: []int{2, 1, 2, 5, 3, 2, 1}},
		{name: "All distinct pops like a stack", pushes: []int{4, 7, 9}, want: []int{9, 7, 4}},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			s := Construct()
			for _, num := range tt.pushes {
				s.Push(num)
			}
			var got []int
			for range tt.want {
				got = append(got, s.Pop())
			}
			if !slices.Equal(got, tt.want) {
				t.Errorf("Pop() order = %v, want %v", got, tt.want)
			}
		})
	}
}
