use super::tripletsumclosetotarget::search_triplet;

#[test]
fn test_search_triplet() {
    let tests = [
        (vec![-1, 0, 2, 3], 3, 2),
        (vec![-3, -1, 1, 2], 1, 0),
        (vec![1, 0, 1, 1], 100, 3),
        (vec![0, 0, 1, 1, 2, 6], 5, 4),
    ];
    for (arr, target, want) in tests {
        let got = search_triplet(&mut arr.clone(), target);
        assert_eq!(got, want, "search_triplet({arr:?}, {target})");
    }
}
