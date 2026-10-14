use super::squareasortedarray::make_squares;

#[test]
fn test_make_squares() {
    let tests = [
        (vec![-2, -1, 0, 2, 3], vec![0, 1, 4, 4, 9]),
        (vec![-3, -1, 0, 1, 2], vec![0, 1, 1, 4, 9]),
        (vec![0], vec![0]),
        (vec![-1], vec![1]),
        (vec![1, 2, 3], vec![1, 4, 9]),
        (vec![-4, -3, -2, -1], vec![1, 4, 9, 16]),
    ];
    for (input, want) in tests {
        let got = make_squares(&input);
        assert_eq!(got, want, "make_squares({input:?})");
    }
}
