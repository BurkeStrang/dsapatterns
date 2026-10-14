use super::subslessthantarget::find_subarrays;

#[test]
fn test_find_subarrays() {
    let tests = [
        (
            "Example 1",
            vec![2, 5, 3, 10],
            30,
            vec![vec![2], vec![2, 5], vec![5], vec![5, 3], vec![3], vec![10]],
        ),
        (
            "Example 2",
            vec![8, 2, 6, 5],
            50,
            vec![
                vec![8],
                vec![8, 2],
                vec![2],
                vec![2, 6],
                vec![6],
                vec![6, 5],
                vec![5],
            ],
        ),
        ("Target 0", vec![10, 5, 2, 6], 0, vec![]),
        ("Single element < target", vec![1], 2, vec![vec![1]]),
        ("Single element >= target", vec![5], 5, vec![]),
    ];
    for (name, arr, target, mut want) in tests {
        let mut got = find_subarrays(&arr, target);
        // the subarrays may come back in any order
        got.sort();
        want.sort();
        assert_eq!(got, want, "{name}: find_subarrays()");
    }
}
