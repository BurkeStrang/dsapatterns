use super::freqstack::FrequencyStack;

#[test]
fn test_frequency_stack() {
    let mut stack = FrequencyStack::new();
    for num in [1, 2, 3, 2, 1, 2, 5] {
        stack.push(num);
    }

    // 2 is the most frequent; then 1 and 2 are tied and 1 was pushed last;
    // then 2; after that every push left is a first push of its number, and
    // the latest of those comes out first
    let want = [2, 1, 2, 5, 3, 2, 1].map(Some).into_iter().chain([None]);
    for (i, want) in want.enumerate() {
        assert_eq!(stack.pop(), want, "pop() number {}", i + 1);
    }
}
