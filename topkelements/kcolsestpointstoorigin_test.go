package topkelements

import "testing"

func Test_findClosestPoints(t *testing.T) {
	tests := []struct {
		name string
		points []*Point
		k      int
		want   []*Point
	}{
		{name: "Example 1", points: []*Point{{X: 1, Y: 2}, {X: 1, Y: 3}}, k: 1, want: []*Point{{X: 1, Y: 2}}},
		{name: "Example 2", points: []*Point{{X: 1, Y: 3}, {X: 3, Y: 4}, {X: 2, Y: -1}}, k: 2, want: []*Point{{X: 1, Y: 3}, {X: 2, Y: -1}}},
		{name: "Example 3", points: []*Point{{X: 1, Y: 2}, {X: 3, Y: 4}, {X: 1, Y: -1}}, k: 2, want: []*Point{{X: 1, Y: -1}, {X: 1, Y: 2}}},
		{name: "Example 4", points: []*Point{{X: 3, Y: 3}, {X: 5, Y: -1}, {X: -2, Y: 4}}, k: 2, want: []*Point{{X: 3, Y: 3}, {X: -2, Y: 4}}},
		{name: "All points are the same", points: []*Point{{X: 1, Y: 1}, {X: 1, Y: 1}, {X: 1, Y: 1}}, k: 2, want: []*Point{{X: 1, Y: 1}, {X: 1, Y: 1}}},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findClosestPoints(tt.points, tt.k)
			if !equal(got, tt.want) {
				t.Errorf("findClosestPoints() = %v, want %v", got, tt.want)
			}
		})
	}
}

func equal(a, b []*Point) bool {
	if len(a) != len(b) {
		return false
	}

	count := make(map[[2]int]int)

	for _, p := range a {
		count[[2]int{p.X, p.Y}]++
	}

	for _, p := range b {
		key := [2]int{p.X, p.Y}
		count[key]--
		if count[key] < 0 {
			return false
		}
	}

	return true
}
