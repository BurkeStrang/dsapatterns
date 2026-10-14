use super::mediannumberstream::Median;

#[test]
fn test_median_stream() {
    let mut m = Median::new();
    let tests = [(1, 1.0), (2, 1.5), (3, 2.0), (4, 2.5), (5, 3.0)];
    for (num, want) in tests {
        m.insert_num(num);
        assert_eq!(m.find_median(), want, "median after inserting {num}");
    }
}

#[test]
fn test_median_stream_unordered() {
    let mut m = Median::new();
    let tests = [(5, 5.0), (3, 4.0), (8, 5.0), (1, 4.0), (2, 3.0)];
    for (num, want) in tests {
        m.insert_num(num);
        assert_eq!(m.find_median(), want, "median after inserting {num}");
    }
}
