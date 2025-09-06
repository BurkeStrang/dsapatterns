package twopointers

import (
	"reflect"
	"testing"
)

func TestDutch(t *testing.T) {
	tests := []struct {
		name string
		in   []int
		want []int
	}{
		{
			name: "example1",
			in:   []int{1, 0, 2, 1, 0},
			want: []int{0, 0, 1, 1, 2},
		},
		{
			name: "example2",
			in:   []int{2, 2, 0, 1, 2, 0},
			want: []int{0, 0, 1, 2, 2, 2},
		},
		{
			name: "all zeros",
			in:   []int{0, 0, 0},
			want: []int{0, 0, 0},
		},
		{
			name: "all twos",
			in:   []int{2, 2, 2},
			want: []int{2, 2, 2},
		},
		{
			name: "already sorted",
			in:   []int{0, 0, 1, 1, 2, 2},
			want: []int{0, 0, 1, 1, 2, 2},
		},
		{
			name: "single element",
			in:   []int{1},
			want: []int{1},
		},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := dutch(append([]int{}, tt.in...)) // copy input to avoid modifying test cases
			if !reflect.DeepEqual(got, tt.want) {
				t.Errorf("dutch(%v) = %v; want %v", tt.in, got, tt.want)
			}
		})
	}
}
