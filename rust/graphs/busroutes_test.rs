use super::busroutes::num_buses_to_destination;

#[test]
fn test_num_buses_to_destination() {
    let tests = [
        ("example 1", vec![vec![1, 2, 7], vec![3, 6, 7]], 1, 6, 2),
        (
            "example 2",
            vec![
                vec![7, 12],
                vec![4, 5, 15],
                vec![6],
                vec![15, 19],
                vec![9, 12, 13],
            ],
            15,
            12,
            -1,
        ),
    ];
    for (name, routes, source, target, want) in tests {
        let got = num_buses_to_destination(&routes, source, target);
        assert_eq!(got, want, "{name}: num_buses_to_destination()");
    }
}
