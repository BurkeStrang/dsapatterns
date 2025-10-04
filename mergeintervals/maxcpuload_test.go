package mergeintervals

import "testing"

func Test_findMaxCPULoad(t *testing.T) {
	tests := []struct {
		name string
		jobs []*Job
		want int
	}{
		{
			name: "Example 1: overlapping jobs",
			jobs: []*Job{{Start: 1, End: 4, CPULoad: 3}, {Start: 2, End: 5, CPULoad: 4}, {Start: 7, End: 9, CPULoad: 6}},
			want: 7,
		},
		{
			name: "Example 2: non-overlapping jobs",
			jobs: []*Job{{Start: 6, End: 7, CPULoad: 10}, {Start: 2, End: 4, CPULoad: 11}, {Start: 8, End: 12, CPULoad: 15}},
			want: 15,
		},
		{
			name: "Example 3: all overlap",
			jobs: []*Job{{Start: 1, End: 4, CPULoad: 2}, {Start: 2, End: 4, CPULoad: 1}, {Start: 3, End: 6, CPULoad: 5}},
			want: 8,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findMaxCPULoad(tt.jobs)
			if got != tt.want {
				t.Errorf("findMaxCPULoad() = %v, want %v", got, tt.want)
			}
		})
	}
}
