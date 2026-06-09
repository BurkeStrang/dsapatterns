package backtracking

// Write a program to solve a Sudoku puzzle by filling the empty cells.
// A sudoku solution must satisfy all of the following rules:
// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.
//
// Example 1:
// Input:
//
//             {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
//             {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
//             {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
//             {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
//             {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
//             {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
//             {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
//             {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
//             {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
// Output:
//
//             {'5'', '3'', '4'', '6'', '7'', '8'', '9'', '1'', '2''},
//             {'6'', '7'', '2'', '1'', '9'', '5'', '3'', '4'', '8''},
//             {'1'', '9'', '8'', '3'', '4'', '2'', '5'', '6'', '7''},
//             {'8'', '5'', '9'', '7'', '6'', '1'', '4'', '2'', '3''},
//             {'4'', '2'', '6'', '8'', '5'', '3'', '7'', '9'', '1''},
//             {'7'', '1'', '3'', '9'', '2'', '4'', '8'', '5'', '6''},
//             {'9'', '6'', '1'', '5'', '3'', '7'', '2'', '8'', '4''},
//             {'2'', '8'', '7'', '4'', '1'', '9'', '6'', '3'', '5''},
//             {'3'', '4'', '5'', '2'', '8'', '6'', '1'', '7'', '9''}
//
// Explanation: The given output is the only valid Sudoku solution.
//
// Constraints:
//
// board.length == 9
// board[i].length == 9
// board[i][j] is a digit or '.'
// It is guaranteed that the input board has only one solution.

// Solves the Sudoku and returns the solved board
func solveSudoku(board [][]byte) [][]byte {
	solve(board)
	return board
}

func solve(board [][]byte) bool {
	for row := range 9 {
		for col := range 9 {
			if board[row][col] == '.' { // If we find an empty cell
				for num := '1'; num <= '9'; num++ { // Try every number from 1-9
					if isValid(board, row, col, byte(num)) { // Check if the number is valid in the current cell
						board[row][col] = byte(num) // If it is valid, fill the cell with the number
						if solve(board) {           // Recursively call the function to solve the rest of the board
							return true
						} else { // If the current number doesn't lead to a solution, backtrack by emptying the cell
							board[row][col] = '.'
						}
					}
				}
				return false // If we have tried every number and none of them lead to a solution, return false
			}
		}
	}
	return true // If the board is completely filled, return true
}

// Helper function to check if a given number is valid in the current cell
func isValid(board [][]byte, row, col int, num byte) bool {
	// Check if we already have the same number in the same row, col or box
	for x := range 9 {
		if board[row][x] == num {
			return false // Check if the same number is in the same row
		}
		if board[x][col] == num {
			return false // Check if the same number is in the same col
		}
		if board[(row/3)*3+x/3][(col/3)*3+x%3] == num {
			return false // Check if the same number is in the same 3x3 box
		}
	}
	return true
}
