use super::tripletessumzero::search_triplets;

#[test]
fn test_search_triplets() {
    let tests = [
        (
            vec![-3, 0, 1, 2, -1, 1, -2],
            vec![
                vec![-3, 1, 2],
                vec![-2, 0, 2],
                vec![-2, 1, 1],
                vec![-1, 0, 1],
            ],
        ),
        (
            vec![-5, 2, -1, -2, 3],
            vec![vec![-5, 2, 3], vec![-2, -1, 3]],
        ),
        (vec![1, 2, 3], vec![]),
    ];
    for (input, want) in tests {
        let mut got = search_triplets(&mut input.clone());
        // the triplets may come back in any order
        got.sort();
        assert_eq!(got, want, "search_triplets({input:?})");
    }
}
