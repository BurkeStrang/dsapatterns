#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct Interval {
    pub start: i32,
    pub end: i32,
}

/// Builds a list of intervals from (start, end) pairs; keeps the test tables
/// short.
pub fn intervals(pairs: &[(i32, i32)]) -> Vec<Interval> {
    pairs
        .iter()
        .map(|&(start, end)| Interval { start, end })
        .collect()
}
