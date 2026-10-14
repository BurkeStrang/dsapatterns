import { describe, expect, test } from "vitest";

import { exist } from "./wordsearch.ts";

// each row of the board is written as a string, one letter per cell
const ROWS = ["ABCE", "SFCS", "ADEE"];

describe("exist", () => {
  test.each([
    { name: "test1", word: "ABCCED", want: true },
    { name: "test2", word: "SEE", want: true },
    { name: "test3", word: "XYZ", want: false },
  ])("$name", ({ word, want }) => {
    const board = ROWS.map((row) => Array.from(row));
    expect(exist(board, word)).toBe(want);
    // the board must be put back the way it was
    expect(board.map((row) => row.join(""))).toEqual(ROWS);
  });
});
