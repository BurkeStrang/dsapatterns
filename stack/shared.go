package stack

import "errors"

type Stack struct {
	items []any
}

func NewStack() Stack {
	return Stack{}
}

func (s *Stack) Empty() bool {
	return len(s.items) == 0
}

func (s *Stack) Push(item any) {
	s.items = append(s.items, item)
}

func (s *Stack) Pop() (any, error) {
	if s.Empty() {
		return nil, errors.New("stack is empty")
	}

	item := s.items[len(s.items)-1]
	s.items = s.items[:len(s.items)-1]
	return item, nil
}

func (s *Stack) Top() (any, error) {
	if s.Empty() {
		return nil, errors.New("stack is empty")
	}

	return s.items[len(s.items)-1], nil
}
