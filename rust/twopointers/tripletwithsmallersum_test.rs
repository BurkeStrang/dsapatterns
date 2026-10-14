use super::tripletwithsmallersum::find_triplets;

#[test]
fn test_find_triplets() {
    let tests = [
        (vec![-1, 0, 2, 3], 3, 2),
        (vec![-1, 4, 2, 1, 3], 5, 4),
        (vec![], 5, 0),
        (vec![1, 2], 3, 0),
    ];
    for (arr, target, want) in tests {
        let got = find_triplets(&mut arr.clone(), target);
        assert_eq!(got, want, "find_triplets({arr:?}, {target})");
    }
}
