const EPSILON: f64 = 1e-9;

/// Reports whether two float slices hold the same values, allowing for
/// rounding error.
pub fn equal_float_slices(a: &[f64], b: &[f64]) -> bool {
    a.len() == b.len() && a.iter().zip(b).all(|(x, y)| (x - y).abs() <= EPSILON)
}
