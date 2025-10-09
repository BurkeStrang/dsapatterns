package hashmaps

import "testing"

func Test_firstUniqChar(t *testing.T) {
	tests := []struct {
		name string
		sStr string
		want int
	}{
		{
			name: "Example 1: apple",
			sStr: "apple",
			want: 0,
		},
		{
			name: "Example 2: abcab",
			sStr: "abcab",
			want: 2,
		},
		{
			name: "Example 3: abab",
			sStr: "abab",
			want: -1,
		},
		{
			name: "Single character",
			sStr: "z",
			want: 0,
		},
		{
			name: "All unique",
			sStr: "abcdef",
			want: 0,
		},
		{
			name: "Last unique",
			sStr: "aabbc",
			want: 4,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := firstUniqChar(tt.sStr)
			if got != tt.want {
				t.Errorf("firstUniqChar() = %v, want %v", got, tt.want)
			}
		})
	}
}

