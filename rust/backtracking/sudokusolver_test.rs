use super::sudokusolver::{Board, solve_sudoku};

#[test]
fn test_solve_sudoku() {
    // each row is written as a byte string, one character per cell
    let mut board: Board = [
        *b"53..7....",
        *b"6..195...",
        *b".98....6.",
        *b"8...6...3",
        *b"4..8.3..1",
        *b"7...2...6",
        *b".6....28.",
        *b"...419..5",
        *b"....8..79",
    ];
    let want: Board = [
        *b"534678912",
        *b"672195348",
        *b"198342567",
        *b"859761423",
        *b"426853791",
        *b"713924856",
        *b"961537284",
        *b"287419635",
        *b"345286179",
    ];

    solve_sudoku(&mut board);

    // compare as text so that a failure prints rows that can be read
    let rows = |board: &Board| {
        board.map(|row| String::from_utf8_lossy(&row).into_owned())
    };
    assert_eq!(rows(&board), rows(&want), "Example 1: solve_sudoku()");
}
