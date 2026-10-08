package graphs

import "testing"

func Test_findProvinces(t *testing.T) {
	tests := []struct {
		name        string
		isConnected [][]int
		want        int
	}{
		{
			name:        "Example 1: Two provinces",
			isConnected: [][]int{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}},
			want:        2,
		},
		{
			name:        "Example 2: Three provinces",
			isConnected: [][]int{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}},
			want:        3,
		},
		{
			name:        "Example 3: Two provinces",
			isConnected: [][]int{{1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 0}, {1, 0, 0, 1}},
			want:        2,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findProvinces(tt.isConnected)
			if got != tt.want {
				t.Errorf("findProvinces() = %v, want %v", got, tt.want)
			}
		})
	}
}
