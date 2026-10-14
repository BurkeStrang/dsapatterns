use super::knapsack01::solve_knapsack;

#[test]
fn test_solve_knapsack() {
    // (name, profits, weights, capacity, want)
    let tests = [
        ("Example", vec![4, 5, 3, 7], vec![2, 3, 1, 4], 5, 10),
        (
            "Second example",
            vec![1, 6, 10, 16],
            vec![1, 2, 3, 5],
            7,
            22,
        ),
        ("Nothing fits", vec![4, 5], vec![3, 4], 2, 0),
    ];
    for (name, profits, weights, capacity, want) in tests {
        let got = solve_knapsack(&profits, &weights, capacity);
        assert_eq!(got, want, "{name}: solve_knapsack()");
    }
}
