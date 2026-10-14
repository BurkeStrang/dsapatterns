use super::narraytree::level_order;
use super::shared::NAryNode;

fn node(val: i32, children: Vec<NAryNode>) -> NAryNode {
    NAryNode { val, children }
}

#[test]
fn test_level_order() {
    let tests = [
        (
            "Example 1: [1,null,2,3,4,null,5,6]",
            Some(node(
                1,
                vec![
                    node(2, vec![node(5, vec![]), node(6, vec![])]),
                    node(3, vec![]),
                    node(4, vec![]),
                ],
            )),
            vec![vec![1], vec![2, 3, 4], vec![5, 6]],
        ),
        ("Single node", Some(node(42, vec![])), vec![vec![42]]),
        ("Empty tree", None, vec![]),
    ];
    for (name, root, want) in tests {
        let got = level_order(root.as_ref());
        assert_eq!(got, want, "{name}: level_order()");
    }
}
