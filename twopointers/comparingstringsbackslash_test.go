package twopointers

import "testing"

func Test_compare(t *testing.T) {
	tests := []struct {
		name string // description of this test case
		str1 string
		str2 string
		want bool
	}{
		{
			name: "Example 1",
			str1: "xy#z",
			str2: "xzz#",
			want: true,
		},
		{
			name: "Example 2",
			str1: "xy#z",
			str2: "xyz#",
			want: false,
		},
		{
			name: "Example 3",
			str1: "xp#",
			str2: "xyz##",
			want: true,
		},
		{
			name: "Example 4",
			str1: "xywrrmp",
			str2: "xywrrmu#p",
			want: true,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := compare(tt.str1, tt.str2)
			if got != tt.want {
				t.Errorf("compare(%q, %q) = %v, want %v", tt.str1, tt.str2, got, tt.want)
			}
		})
	}
}
