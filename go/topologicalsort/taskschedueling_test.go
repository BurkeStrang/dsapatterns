package topologicalsort

import "testing"

func TestTaskScheduel_isSchedulingPossible(t *testing.T) {
	tests := []struct {
		name          string
		tasks         int
		prerequisites [][]int
		want          bool
	}{
		{name: "Test Case 1", tasks: 3, prerequisites: [][]int{{0, 1}, {1, 2}}, want: true},
		{name: "Test Case 2", tasks: 3, prerequisites: [][]int{{0, 1}, {1, 2}, {2, 0}}, want: false},
		{name: "Test Case 3", tasks: 4, prerequisites: [][]int{{0, 1}, {1, 2}, {2, 3}}, want: true},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			var s TaskScheduel
			got := s.isSchedulingPossible(tt.tasks, tt.prerequisites)
			if got != tt.want {
				t.Errorf("isSchedulingPossible() = %v, want %v", got, tt.want)
			}
		})
	}
}
