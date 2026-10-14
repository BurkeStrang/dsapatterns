use std::cmp::Ordering;

// There are n cities. Some of them are connected in a network.
// If City A is directly connected to City B,
// and City B is directly connected to City C,
// city A is indirectly connected to City C.
//
// If a group of cities are connected directly or indirectly,
// they form a province.
// Given an n x n matrix isConnected where isConnected[i][j] = 1
// if the ith city and the jth city are directly connected,
// and isConnected[i][j] = 0 otherwise, determine the total number of provinces.
//
// Example 1:
// Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
// Expected Output: 2
// Justification: Here, city 1 and 2 form a single provenance, and city 3 is one
// province itself.
//
// Example 2:
// Input: isConnected = [1,0,0],[0,1,0],[0,0,1]]
// Expected Output: 3
// Justification: In this scenario, no cities are connected to each other, so
// each city forms its own province.
//
// Example 3:
// Input: isConnected = [[1,0,0,1],[0,1,1,0],[0,1,1,0],[1,0,0,1]]
// Expected Output: 2
// Justification: Cities 1 and 4 form a province, and cities 2 and 3 form
// another province,
// resulting in a total of 2 provinces.
//
// Constraints:
// 1 <= n <= 200
// n == isConnected.length
// n == isConnected[i].length
// isConnected[i][j] is 1 or 0.
// isConnected[i][i] == 1
// isConnected[i][j] == isConnected[j][i]

struct UnionFind {
    parent: Vec<usize>,
    rank: Vec<usize>,
}

impl UnionFind {
    fn new(size: usize) -> Self {
        UnionFind {
            parent: (0..size).collect(),
            rank: vec![0; size],
        }
    }

    fn find(&mut self, x: usize) -> usize {
        if self.parent[x] != x {
            self.parent[x] = self.find(self.parent[x]); // Path compression
        }
        self.parent[x]
    }

    fn union_set(&mut self, x: usize, y: usize) {
        let root_x = self.find(x);
        let root_y = self.find(y);

        // If they are in the same set, do nothing.
        if root_x == root_y {
            return;
        }

        // Union by rank
        match self.rank[root_x].cmp(&self.rank[root_y]) {
            Ordering::Less => self.parent[root_x] = root_y,
            Ordering::Greater => self.parent[root_y] = root_x,
            Ordering::Equal => {
                self.parent[root_y] = root_x;
                self.rank[root_x] += 1;
            }
        }
    }
}

pub fn find_provinces(is_connected: &[Vec<i32>]) -> usize {
    let n = is_connected.len();
    let mut uf = UnionFind::new(n);
    let mut number_of_provinces = n;

    // Iterate over each pair of nodes and union the sets if there is a
    // connection.
    for i in 0..n {
        for j in i + 1..n {
            if is_connected[i][j] == 1 && uf.find(i) != uf.find(j) {
                number_of_provinces -= 1;
                uf.union_set(i, j);
            }
        }
    }

    number_of_provinces
}
