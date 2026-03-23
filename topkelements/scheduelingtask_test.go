package topkelements

import "testing"

func Test_scheduleTasks(t *testing.T) {
	tests := []struct {
		name  string
		tasks []string
		k     int
		want  int
	}{
		{name: "Example 1", tasks: []string{"a", "a", "a", "b", "c", "c"}, k: 2, want: 7},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := scheduleTasks(tt.tasks, tt.k)
			if got != tt.want {
				t.Errorf("scheduleTasks() = %v, want %v", got, tt.want)
			}
		})
	}
}
