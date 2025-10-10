package hashmaps

import "testing"

func Test_canConstruct(t *testing.T) {
	tests := []struct {
		name       string
		ransomNote string
		magazine   string
		want       bool
	}{
		{
			name:       "can construct hello from hellworld",
			ransomNote: "hello",
			magazine:   "hellworld",
			want:       true,
		},
		{
			name:       "can construct notes from stoned",
			ransomNote: "notes",
			magazine:   "stoned",
			want:       true,
		},
		{
			name:       "cannot construct apple from pale",
			ransomNote: "apple",
			magazine:   "pale",
			want:       false,
		},
		{
			name:       "exact match",
			ransomNote: "abc",
			magazine:   "abc",
			want:       true,
		},
		{
			name:       "not enough letters",
			ransomNote: "aabb",
			magazine:   "ab",
			want:       false,
		},
		{
			name:       "empty ransom note",
			ransomNote: "",
			magazine:   "anything",
			want:       true,
		},
		{
			name:       "empty magazine",
			ransomNote: "a",
			magazine:   "",
			want:       false,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := canConstruct(tt.ransomNote, tt.magazine)
			if got != tt.want {
				t.Errorf("canConstruct() = %v, want %v", got, tt.want)
			}
		})
	}
}
