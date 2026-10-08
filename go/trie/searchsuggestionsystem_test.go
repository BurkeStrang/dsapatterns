package trie

import "testing"

func TestSuggestion_suggestedProducts(t *testing.T) {
	tests := []struct {
		name       string
		products   []string
		searchWord string
		want       [][]string
	}{
		{name: "Test Case 1", products: []string{"mobile", "mouse", "moneypot", "monitor", "mousepad"}, searchWord: "mouse", want: [][]string{{"mobile", "moneypot", "monitor"}, {"mobile", "moneypot", "monitor"}, {"mouse", "mousepad"}, {"mouse", "mousepad"}, {"mouse", "mousepad"}}},
		{name: "Test Case 2", products: []string{"havana"}, searchWord: "havana", want: [][]string{{"havana"}, {"havana"}, {"havana"}, {"havana"}, {"havana"}, {"havana"}}},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			var s Suggestion
			got := s.suggestedProducts(tt.products, tt.searchWord)
			if !equalStringSlices(got, tt.want) {
				t.Errorf("suggestedProducts() = %v, want %v", got, tt.want)
			}
		})
	}
}

func equalStringSlices(a, b [][]string) bool {
	if len(a) != len(b) {
		return false
	}
	for i := range a {
		if len(a[i]) != len(b[i]) {
			return false
		}
		for j := range a[i] {
			if a[i][j] != b[i][j] {
				return false
			}
		}
	}
	return true
}
