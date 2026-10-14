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

export class UnionFind {
  private readonly parent: number[];
  private readonly rank: number[];

  constructor(size: number) {
    this.parent = Array.from({ length: size }, (_, i) => i);
    this.rank = new Array<number>(size).fill(0);
  }

  find(x: number): number {
    if (this.parent[x] !== x) {
      this.parent[x] = this.find(this.parent[x]); // Path compression
    }
    return this.parent[x];
  }

  unionSet(x: number, y: number): void {
    const rootX = this.find(x);
    const rootY = this.find(y);

    // If they are in the same set, do nothing.
    if (rootX === rootY) {
      return;
    }

    // Union by rank
    if (this.rank[rootX] < this.rank[rootY]) {
      this.parent[rootX] = rootY;
    } else if (this.rank[rootX] > this.rank[rootY]) {
      this.parent[rootY] = rootX;
    } else {
      this.parent[rootY] = rootX;
      this.rank[rootX]++;
    }
  }
}

export function findProvinces(isConnected: number[][]): number {
  const n = isConnected.length;
  const uf = new UnionFind(n);
  let numberOfProvinces = n;

  // Iterate over each pair of nodes and union the sets if there is a
  // connection.
  for (let i = 0; i < n; i++) {
    for (let j = i + 1; j < n; j++) {
      if (isConnected[i][j] === 1 && uf.find(i) !== uf.find(j)) {
        numberOfProvinces--;
        uf.unionSet(i, j);
      }
    }
  }
  return numberOfProvinces;
}
