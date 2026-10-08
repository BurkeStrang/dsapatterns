package twoheaps

import (
	"testing"
)

func TestMedianStream(t *testing.T) {
	m := Constructor()

	tests := []struct {
		num      int
		expected float64
	}{
		{1, 1.0},
		{2, 1.5},
		{3, 2.0},
		{4, 2.5},
		{5, 3.0},
	}

	for i, tt := range tests {
		m.insertNum(tt.num)
		median := m.findMedian()
		if median != tt.expected {
			t.Errorf("After inserting %d numbers, expected median %.1f, got %.1f (step %d)", i+1, tt.expected, median, i+1)
		}
	}
}

func TestMedianStreamUnordered(t *testing.T) {
	m := Constructor()
	nums := []int{5, 3, 8, 1, 2}
	expected := []float64{5, 4, 5, 4, 3}

	for i, num := range nums {
		m.insertNum(num)
		median := m.findMedian()
		if median != expected[i] {
			t.Errorf("After inserting %d, expected median %.1f, got %.1f", num, expected[i], median)
		}
	}
}
