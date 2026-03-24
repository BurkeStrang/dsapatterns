package kwaymerge

import "testing"

func Test_merge(t *testing.T) {
	tests := []struct {
		name  string
		lists []*ListNode
		want  *ListNode
	}{
		{
			name: "Example 1",
			lists: []*ListNode{
				{Val: 2, Next: &ListNode{Val: 6, Next: &ListNode{Val: 8}}},
				{Val: 3, Next: &ListNode{Val: 6, Next: &ListNode{Val: 7}}},
				{Val: 1, Next: &ListNode{Val: 3, Next: &ListNode{Val: 4}}},
			},
			want: &ListNode{
				Val: 1, Next: &ListNode{
					Val: 2, Next: &ListNode{
						Val: 3, Next: &ListNode{
							Val: 3, Next: &ListNode{
								Val: 4, Next: &ListNode{
									Val: 6, Next: &ListNode{
										Val: 6, Next: &ListNode{
											Val: 7, Next: &ListNode{
												Val: 8,
											},
										},
									},
								},
							},
						},
					},
				},
			},
		},
		{
			name: "Example 2",
			lists: []*ListNode{
				{Val: 5, Next: &ListNode{Val: 8, Next: &ListNode{Val: 9}}},
				{Val: 1, Next: &ListNode{Val: 7}},
			},
			want: &ListNode{
				Val: 1, Next: &ListNode{
					Val: 5, Next: &ListNode{
						Val: 7, Next: &ListNode{
							Val: 8, Next: &ListNode{
								Val: 9,
							},
						},
					},
				},
			},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := merge(tt.lists)
			if !equalList(got, tt.want) {
				t.Errorf("merge() = %v, want %v", got, tt.want)
			}
		})
	}
}

func equalList(a *ListNode, b *ListNode) bool {
	for a != nil && b != nil {
		if a.Val != b.Val {
			return false
		}
		a = a.Next
		b = b.Next
	}
	return a == nil && b == nil
}
