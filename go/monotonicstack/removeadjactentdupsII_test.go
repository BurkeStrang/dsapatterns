package monotonicstack

import "testing"

func Test_removeDuplicatesII(t *testing.T) {
	tests := []struct {
		name string
		s    string
		k    int
		want string
	}{
		{
			name: "remove bbb then aaa",
			s:    "abbbaaca",
			k:    3,
			want: "ca",
		},
		{
			name: "no removal possible",
			s:    "abbaccaa",
			k:    3,
			want: "abbaccaa",
		},
		{
			name: "remove ccc then aaa",
			s:    "abbacccaa",
			k:    3,
			want: "abb",
		},
		{
			name: "all removed",
			s:    "aaa",
			k:    3,
			want: "",
		},
		{
			name: "single char, k=2",
			s:    "a",
			k:    2,
			want: "a",
		},
		{
			name: "multiple removals",
			s:    "deeedbbcccbdaa",
			k:    3,
			want: "aa",
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := removeDuplicatesII(tt.s, tt.k)
			if got != tt.want {
				t.Errorf("removeDuplicatesII() = %v, want %v", got, tt.want)
			}
		})
	}
}
