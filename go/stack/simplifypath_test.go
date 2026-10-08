package stack

import "testing"

func Test_simplifyPath(t *testing.T) {
	tests := []struct {
		name string
		path string
		want string
	}{
		{
			name: "Example 1",
			path: "/a//b////c/d//././/..",
			want: "/a/b/c",
		},
		{
			name: "Example 2",
			path: "/../",
			want: "/",
		},
		{
			name: "Example 3",
			path: "/home//foo/",
			want: "/home/foo",
		},
		{
			name: "Root only",
			path: "/",
			want: "/",
		},
		{
			name: "Multiple .. at root",
			path: "/../../..",
			want: "/",
		},
		{
			name: "Dot only",
			path: "/./././.",
			want: "/",
		},
		{
			name: "Trailing slash",
			path: "/a/b/c/",
			want: "/a/b/c",
		},
		{
			name: "Complex",
			path: "/a/./b/../../c/",
			want: "/c",
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := simplifyPath(tt.path)
			if got != tt.want {
				t.Errorf("simplifyPath() = %v, want %v", got, tt.want)
			}
		})
	}
}
