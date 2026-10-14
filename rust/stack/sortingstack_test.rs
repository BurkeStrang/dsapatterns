use super::sortingstack::sort_stack;

#[test]
fn test_sort_stack() {
    // the stacks are written with the bottom element first and the top last
    let tests = [
        (
            "Example 1",
            vec![34, 3, 31, 98, 92, 23],
            vec![3, 23, 31, 34, 92, 98],
        ),
        (
            "Example 2",
            vec![4, 3, 2, 10, 12, 1, 5, 6],
            vec![1, 2, 3, 4, 5, 6, 10, 12],
        ),
        ("Example 3", vec![20, 10, -5, -1], vec![-5, -1, 10, 20]),
    ];
    for (name, input, want) in tests {
        let got = sort_stack(input);
        assert_eq!(got, want, "{name}: sort_stack()");
    }
}
