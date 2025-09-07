package slidingwindow

import "testing"

func Test_findAverages(t *testing.T) {
	tests := []struct {
		name string // description of this test case
		// Named input parameters for target function.
		K    int
		arr  []int
		want []float64
	}{
		{
			name: "basic case",
			K:    5,
			arr:  []int{1, 3, 2, 6, -1, 4, 1, 8, 2},
			want: []float64{2.2, 2.8, 2.4, 3.6, 2.8},
		},
		{
			name: "window size 1",
			K:    1,
			arr:  []int{5, 10, 15},
			want: []float64{5.0, 10.0, 15.0},
		},
		{
			name: "window size equals array length",
			K:    4,
			arr:  []int{2, 4, 6, 8},
			want: []float64{5.0},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findAverages(tt.K, tt.arr)
			if !equalFloatSlices(got, tt.want) {
				t.Errorf("findAverages() = %v, want %v", got, tt.want)
			}
		})
	}
}

