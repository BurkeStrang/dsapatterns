use super::maxcpuload::{Job, find_max_cpu_load};

fn jobs(triples: &[(i32, i32, i32)]) -> Vec<Job> {
    triples
        .iter()
        .map(|&(start, end, cpu_load)| Job {
            start,
            end,
            cpu_load,
        })
        .collect()
}

#[test]
fn test_find_max_cpu_load() {
    let tests = [
        (
            "Example 1: overlapping jobs",
            jobs(&[(1, 4, 3), (2, 5, 4), (7, 9, 6)]),
            7,
        ),
        (
            "Example 2: non-overlapping jobs",
            jobs(&[(6, 7, 10), (2, 4, 11), (8, 12, 15)]),
            15,
        ),
        (
            "Example 3: all overlap",
            jobs(&[(1, 4, 2), (2, 4, 1), (3, 6, 5)]),
            8,
        ),
    ];
    for (name, mut jobs, want) in tests {
        let got = find_max_cpu_load(&mut jobs);
        assert_eq!(got, want, "{name}: find_max_cpu_load()");
    }
}
