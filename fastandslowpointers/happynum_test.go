package fastandslowpointers

import "testing"

func Test_isHappy(t *testing.T) {
	tests := []struct {
		name string
		num  int
		want bool
	}{
		{
			name: "Happy number 19",
			num:  19,
			want: true,
		},
		{
			name: "Happy number 1",
			num:  1,
			want: true,
		},
		{
			name: "Unhappy number 2",
			num:  2,
			want: false,
		},
		{
			name: "Unhappy number 4",
			num:  4,
			want: false,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := isHappy(tt.num)
			if got != tt.want {
				t.Errorf("isHappy(%v) = %v, want %v", tt.num, got, tt.want)
			}
		})
	}
}
