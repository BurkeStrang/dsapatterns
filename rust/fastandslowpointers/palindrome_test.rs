use super::palindrome::is_palindrome;
use super::shared::{build_list, list_to_vec};

#[test]
fn test_is_palindrome() {
    let tests = [
        (vec![2, 4, 6, 4, 2], true),
        (vec![2, 4, 6, 4, 2, 2], false),
        (vec![], true),
        (vec![1], true),
    ];
    for (input, want) in tests {
        let head = build_list(&input);
        let got = is_palindrome(&head);
        assert_eq!(got, want, "is_palindrome({input:?})");
        // the list must be put back the way it was
        assert_eq!(list_to_vec(&head), input, "list after is_palindrome()");
    }
}
