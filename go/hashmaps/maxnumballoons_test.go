package hashmaps

import "testing"

func Test_maxNumberOfBalloons(t *testing.T) {
	tests := []struct {
		name string
		text string
		want int
	}{
		{
			name: "Example 1",
			text: "balloonballoon",
			want: 2,
		},
		{
			name: "Example 2",
			text: "bbaall",
			want: 0,
		},
		{
			name: "Example 3",
			text: "balloonballoooon",
			want: 2,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := maxNumberOfBalloons(tt.text)
			if got != tt.want {
				t.Errorf("maxNumberOfBalloons() = %v, want %v", got, tt.want)
			}
		})
	}
}
