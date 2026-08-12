package topologicalsort

import "testing"

func Test_findOrder(t *testing.T) {
	tests := []struct {
		name          string
		tasks         int
		prerequisites [][]int
		want          []int
	}{
		{name: "Test Case 1", tasks: 6, prerequisites: [][]int{{2, 5}, {0, 5}, {0, 4}, {1, 4}, {3, 2}, {1, 3}}, want: []int{0, 1, 4, 3, 2, 5}},
		{name: "Test Case 2", tasks: 3, prerequisites: [][]int{{0, 1}, {1, 2}}, want: []int{0, 1, 2}},
		{name: "Test Case 3", tasks: 3, prerequisites: [][]int{{0, 1}, {1, 2}, {2, 0}}, want: []int{}},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findOrder(tt.tasks, tt.prerequisites)
			if !equalSlices(got, tt.want) {
				t.Errorf("findOrder() = %v, want %v", got, tt.want)
			}
		})
	}
}
