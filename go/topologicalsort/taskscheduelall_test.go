package topologicalsort

import (
	"fmt"
	"reflect"
	"sort"
	"testing"
)

func Test_printOrders(t *testing.T) {
	// want lists every valid ordering; they can come back in any order
	tests := []struct {
		name          string
		tasks         int
		prerequisites [][]int
		want          [][]int
	}{
		{
			name:          "Example 1: two orderings",
			tasks:         4,
			prerequisites: [][]int{{3, 2}, {3, 0}, {2, 0}, {2, 1}},
			want:          [][]int{{3, 2, 0, 1}, {3, 2, 1, 0}},
		},
		{
			name:          "Example 2: one ordering",
			tasks:         3,
			prerequisites: [][]int{{0, 1}, {1, 2}},
			want:          [][]int{{0, 1, 2}},
		},
		{
			name:          "Example 3: thirteen orderings",
			tasks:         6,
			prerequisites: [][]int{{2, 5}, {0, 5}, {0, 4}, {1, 4}, {3, 2}, {1, 3}},
			want: [][]int{
				{0, 1, 4, 3, 2, 5},
				{0, 1, 3, 4, 2, 5},
				{0, 1, 3, 2, 4, 5},
				{0, 1, 3, 2, 5, 4},
				{1, 0, 3, 4, 2, 5},
				{1, 0, 3, 2, 4, 5},
				{1, 0, 3, 2, 5, 4},
				{1, 0, 4, 3, 2, 5},
				{1, 3, 0, 2, 4, 5},
				{1, 3, 0, 2, 5, 4},
				{1, 3, 0, 4, 2, 5},
				{1, 3, 2, 0, 5, 4},
				{1, 3, 2, 0, 4, 5},
			},
		},
		{
			name:          "No prerequisites: every arrangement",
			tasks:         3,
			prerequisites: [][]int{},
			want: [][]int{
				{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0},
			},
		},
		{
			name:          "Cyclic prerequisites: no ordering",
			tasks:         3,
			prerequisites: [][]int{{0, 1}, {1, 2}, {2, 0}},
			want:          [][]int{},
		},
		{name: "No tasks", tasks: 0, prerequisites: [][]int{}, want: [][]int{}},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := sortedOrderings(printOrders(tt.tasks, tt.prerequisites))
			want := sortedOrderings(tt.want)
			if !reflect.DeepEqual(got, want) {
				t.Errorf("printOrders() = %d orderings %v, want %d %v",
					len(got), got, len(want), want)
			}
		})
	}
}

// sortedOrderings formats every ordering as text and sorts them, so two
// lists of orderings can be compared no matter what order they came back in.
func sortedOrderings(orders [][]int) []string {
	formatted := make([]string, 0, len(orders))
	for _, order := range orders {
		formatted = append(formatted, fmt.Sprint(order))
	}
	sort.Strings(formatted)
	return formatted
}
