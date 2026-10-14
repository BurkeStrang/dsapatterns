import { expect, test } from "vitest";

import { solveSudoku } from "./sudokusolver.ts";

test("Example 1", () => {
  // each row is written as a string, one character per cell
  const rows = [
    "53..7....",
    "6..195...",
    ".98....6.",
    "8...6...3",
    "4..8.3..1",
    "7...2...6",
    ".6....28.",
    "...419..5",
    "....8..79",
  ];
  const want = [
    "534678912",
    "672195348",
    "198342567",
    "859761423",
    "426853791",
    "713924856",
    "961537284",
    "287419635",
    "345286179",
  ];
  const board = rows.map((row) => Array.from(row));
  solveSudoku(board);
  expect(board.map((row) => row.join(""))).toEqual(want);
});
