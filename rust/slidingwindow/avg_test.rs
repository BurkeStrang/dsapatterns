use super::avg::find_averages;
use super::shared::equal_float_slices;

#[test]
fn test_find_averages() {
    struct Test {
        name: &'static str, // description of this test case
        k: usize,
        arr: Vec<i32>,
        want: Vec<f64>,
    }
    let tests = [
        Test {
            name: "basic case",
            k: 5,
            arr: vec![1, 3, 2, 6, -1, 4, 1, 8, 2],
            want: vec![2.2, 2.8, 2.4, 3.6, 2.8],
        },
        Test {
            name: "window size 1",
            k: 1,
            arr: vec![5, 10, 15],
            want: vec![5.0, 10.0, 15.0],
        },
        Test {
            name: "window size equals array length",
            k: 4,
            arr: vec![2, 4, 6, 8],
            want: vec![5.0],
        },
    ];
    for tt in tests {
        let got = find_averages(tt.k, &tt.arr);
        assert!(
            equal_float_slices(&got, &tt.want),
            "{}: find_averages() = {:?}, want {:?}",
            tt.name,
            got,
            tt.want
        );
    }
}
