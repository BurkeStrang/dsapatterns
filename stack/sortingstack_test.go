package stack

import (
	"reflect"
	"testing"
)

func Test_sortStack(t *testing.T) {
	tests := []struct {
		name string
		input Stack
		want  Stack
	}{
		{
			name:  "Example 1",
			input: makeStack([]int{34, 3, 31, 98, 92, 23}),
			want:  makeStack([]int{3, 23, 31, 34, 92, 98}),
		},
		{
			name:  "Example 2",
			input: makeStack([]int{4, 3, 2, 10, 12, 1, 5, 6}),
			want:  makeStack([]int{1, 2, 3, 4, 5, 6, 10, 12}),
		},
		{
			name:  "Example 3",
			input: makeStack([]int{20, 10, -5, -1}),
			want:  makeStack([]int{-5, -1, 10, 20}),
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := sortStack(tt.input)
			gotSlice := stackToSlice(got)
			wantSlice := stackToSlice(tt.want)
			if !reflect.DeepEqual(gotSlice, wantSlice) {
				t.Errorf("sortStack() = %v, want %v", gotSlice, wantSlice)
			}
		})
	}
}


func makeStack(vals []int) Stack {
	s := NewStack()
	for _, v := range vals {
		s.Push(v)
	}
	return s
}

// stackToSlice converts a Stack to a slice of ints, with the bottom element first and top last.
func stackToSlice(s Stack) []int {
	out := []int{}
	tmp := NewStack()
	for !s.Empty() {
		val, _ := s.Pop()
		tmp.Push(val)
	}
	for !tmp.Empty() {
		val, _ := tmp.Pop()
		out = append(out, val.(int))
	}
	return out
}

