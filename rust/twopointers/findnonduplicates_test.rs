use super::findnonduplicates::move_elements;

#[test]
fn test_move_elements() {
    let tests = [
        (vec![2, 3, 3, 3, 6, 9, 9], vec![2, 3, 6, 9]),
        (vec![2, 2, 2, 11], vec![2, 11]),
        (vec![1, 2, 2], vec![1, 2]),
        (vec![0, 0, 1, 1, 1, 2, 2, 3, 3, 4], vec![0, 1, 2, 3, 4]),
        (vec![1], vec![1]),
        (vec![1, 2, 3], vec![1, 2, 3]),
    ];
    for (input, want) in tests {
        let mut arr = input.clone();
        let got = move_elements(&mut arr);
        assert_eq!(got, want.len(), "move_elements({input:?}) length");
        assert_eq!(arr[..got], want, "move_elements({input:?}) elements");
    }
}
