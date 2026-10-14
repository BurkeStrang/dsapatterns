use super::dupsubsets::find_dup_subsets;
use super::shared::sorted_subsets;

#[test]
fn test_find_dup_subsets() {
    let tests = [
        (
            "example test case 1",
            vec![1, 3, 3],
            vec![
                vec![],
                vec![1],
                vec![3],
                vec![1, 3],
                vec![3, 3],
                vec![1, 3, 3],
            ],
        ),
        (
            "example test case 2",
            vec![1, 2, 3],
            vec![
                vec![],
                vec![1],
                vec![2],
                vec![3],
                vec![1, 2],
                vec![1, 3],
                vec![2, 3],
                vec![1, 2, 3],
            ],
        ),
    ];
    for (name, mut nums, want) in tests {
        let got = find_dup_subsets(&mut nums);
        assert_eq!(
            sorted_subsets(got),
            sorted_subsets(want),
            "{name}: find_dup_subsets()"
        );
    }
}
