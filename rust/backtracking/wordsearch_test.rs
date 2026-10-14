use super::wordsearch::exist;

#[test]
fn test_exist() {
    // each row of the board is written as a string, one letter per cell
    let board = ["ABCE", "SFCS", "ADEE"];
    let tests = [
        ("test1", "ABCCED", true),
        ("test2", "SEE", true),
        ("test3", "XYZ", false),
    ];
    for (name, word, want) in tests {
        let mut cells: Vec<Vec<u8>> =
            board.iter().map(|row| row.as_bytes().to_vec()).collect();
        let got = exist(&mut cells, word);
        assert_eq!(got, want, "{name}: exist()");
    }
}
