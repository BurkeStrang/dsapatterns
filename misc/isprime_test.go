package misc

import (
	"slices"
	"testing"
)

func Test_isprime(t *testing.T) {
	tests := []struct {
		name string
		n    int
		want bool
	}{
		{name: "1", n: 1, want: false},
		{name: "2", n: 2, want: true},
		{name: "3", n: 3, want: true},
		{name: "4", n: 4, want: false},
		{name: "5", n: 5, want: true},
		{name: "167", n: 167, want: true},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := isPrime(tt.n)
			if got != tt.want {
				t.Errorf("isPrime() = %v, want %v", got, tt.want)
			}
		})
	}
}

func Test_countprimes(t *testing.T) {
	tests := []struct {
		name string
		n    int
		want int
	}{
		{name: "1", n: 1, want: 0},
		{name: "10", n: 10, want: 4},
		{name: "100", n: 100, want: 25},
		{name: "1000", n: 1000, want: 168},
		{name: "10000", n: 10000, want: 1229},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := countPrimes(tt.n)
			if got != tt.want {
				t.Errorf("countPrimes() = %v, want %v", got, tt.want)
			}
		})
	}
}

func Test_getprimes(t *testing.T) {
	tests := []struct {
		name string
		n    int
		want []int
	}{
		{name: "1", n: 1, want: []int{}},
		{name: "10", n: 10, want: []int{2, 3, 5, 7}},
		{name: "20", n: 20, want: []int{2, 3, 5, 7, 11, 13, 17, 19}},
		{name: "30", n: 30, want: []int{2, 3, 5, 7, 11, 13, 17, 19, 23, 29}},
		{name: "100", n: 100, want: []int{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97}},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := getPrimes(tt.n)
			if !slices.Equal(got, tt.want) {
				t.Errorf("getPrimes() = %v, want %v", got, tt.want)
			}
		})
	}
}
