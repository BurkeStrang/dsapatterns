package slidingwindow

import "testing"

func Test_findLength(t *testing.T) {
	tests := []struct {
		name string
		str  string
		k    int
		want int
	}{
		{
			name: "Example 1",
			str:  "araaci",
			k:    2,
			want: 4,
		},
		{
			name: "Example 2",
			str:  "araaci",
			k:    1,
			want: 2,
		},
		{
			name: "Example 3",
			str:  "cbbebi",
			k:    3,
			want: 5,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findLength(tt.str, tt.k)
			if got != tt.want {
				t.Errorf("findLength() = %v, want %v", got, tt.want)
			}
		})
	}
}
