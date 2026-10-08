package slidingwindow

import "testing"

func Test_maxFruit(t *testing.T) {
	tests := []struct {
		name string
		arr  []rune
		want int
	}{
		{
			name: "basic example",
			arr:  []rune{'A', 'B', 'C', 'A', 'C'},
			want: 3,
		},
		{
			name: "all same fruit",
			arr:  []rune{'A', 'A', 'A', 'A'},
			want: 4,
		},
		{
			name: "two types alternating",
			arr:  []rune{'A', 'B', 'A', 'B', 'A', 'B'},
			want: 6,
		},
		{
			name: "three types",
			arr:  []rune{'A', 'B', 'C', 'B', 'B', 'C', 'A'},
			want: 5,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := maxFruit(tt.arr)
			if got != tt.want {
				t.Errorf("maxFruit() = %v, want %v", got, tt.want)
			}
		})
	}
}
