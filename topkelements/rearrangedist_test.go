package topkelements

import "testing"

func Test_reorganizeString(t *testing.T) {
	tests := []struct {
		name string
		str  string
		k    int
		want string
	}{
		{name: "Example 1", str: "mmpp", k: 2, want: "mpmp"},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := reorganizeString(tt.str, tt.k)
			if got != tt.want {
				t.Errorf("reorganizeString() = %v, want %v", got, tt.want)
			}
		})
	}
}
