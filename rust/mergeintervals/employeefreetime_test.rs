use super::employeefreetime::find_employee_free_time;
use super::shared::intervals;

#[test]
fn test_find_employee_free_time() {
    let tests = [
        (
            "Example 1: two employees, one free interval",
            vec![intervals(&[(1, 3), (5, 6)]), intervals(&[(2, 3), (6, 8)])],
            intervals(&[(3, 5)]),
        ),
        (
            "Example 2: three employees, two free intervals",
            vec![
                intervals(&[(1, 3), (9, 12)]),
                intervals(&[(2, 4)]),
                intervals(&[(6, 8)]),
            ],
            intervals(&[(4, 6), (8, 9)]),
        ),
        (
            "Example 3: three employees, one free interval",
            vec![
                intervals(&[(1, 3)]),
                intervals(&[(2, 4)]),
                intervals(&[(3, 5), (7, 9)]),
            ],
            intervals(&[(5, 7)]),
        ),
    ];
    for (name, schedule, want) in tests {
        let got = find_employee_free_time(&schedule);
        assert_eq!(got, want, "{name}: find_employee_free_time()");
    }
}
