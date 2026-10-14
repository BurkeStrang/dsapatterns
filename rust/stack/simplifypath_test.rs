use super::simplifypath::simplify_path;

#[test]
fn test_simplify_path() {
    let tests = [
        ("Example 1", "/a//b////c/d//././/..", "/a/b/c"),
        ("Example 2", "/../", "/"),
        ("Example 3", "/home//foo/", "/home/foo"),
        ("Root only", "/", "/"),
        ("Multiple .. at root", "/../../..", "/"),
        ("Dot only", "/./././.", "/"),
        ("Trailing slash", "/a/b/c/", "/a/b/c"),
        ("Complex", "/a/./b/../../c/", "/c"),
    ];
    for (name, path, want) in tests {
        let got = simplify_path(path);
        assert_eq!(got, want, "{name}: simplify_path()");
    }
}
