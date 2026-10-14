/// Reports whether `order` lists every vertex once, with each edge's parent
/// before its child. A graph usually has more than one valid order, so the
/// tests check the order this way instead of comparing it with a fixed
/// answer.
pub fn is_topological_order(
    order: &[usize],
    vertices: usize,
    edges: &[[usize; 2]],
) -> bool {
    if order.len() != vertices {
        return false;
    }

    // position[v] is where vertex 'v' sits in the order
    let mut position = vec![None; vertices];
    for (i, &vertex) in order.iter().enumerate() {
        if vertex >= vertices || position[vertex].is_some() {
            return false;
        }
        position[vertex] = Some(i);
    }

    edges
        .iter()
        .all(|&[parent, child]| position[parent] < position[child])
}
