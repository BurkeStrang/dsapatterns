use super::quadruplesumtotarget::search_quadruplets;

#[test]
fn test_search_quadruplets() {
    let tests = [
        (
            vec![4, 1, 2, -1, 1, -3],
            1,
            vec![vec![-3, -1, 1, 4], vec![-3, 1, 1, 2]],
        ),
        (
            vec![2, 0, -1, 1, -2, 2],
            2,
            vec![vec![-2, 0, 2, 2], vec![-1, 0, 1, 2]],
        ),
    ];
    for (arr, target, want) in tests {
        let mut got = search_quadruplets(&mut arr.clone(), target);
        // the quadruplets may come back in any order
        got.sort();
        assert_eq!(got, want, "search_quadruplets({arr:?}, {target})");
    }
}
