// Helpers shared by the union find problems.

// UnionFind keeps track of which set every element belongs to. Each set is a
// tree, and the root of the tree stands for the whole set.
export class UnionFind {
  private readonly parent: number[];
  private readonly rank: number[];

  // Makes 'size' sets, each holding one element.
  constructor(size: number) {
    this.parent = Array.from({ length: size }, (_, i) => i);
    this.rank = new Array<number>(size).fill(0);
  }

  // find returns the root of the set that x belongs to.
  find(x: number): number {
    if (this.parent[x] !== x) {
      this.parent[x] = this.find(this.parent[x]); // Path compression
    }
    return this.parent[x];
  }

  // unite merges the sets that x and y belong to.
  unite(x: number, y: number): void {
    const rootX = this.find(x);
    const rootY = this.find(y);

    if (rootX === rootY) {
      return;
    }

    // Union by rank: hang the shorter tree under the taller one
    if (this.rank[rootX] < this.rank[rootY]) {
      this.parent[rootX] = rootY;
    } else if (this.rank[rootX] > this.rank[rootY]) {
      this.parent[rootY] = rootX;
    } else {
      this.parent[rootY] = rootX;
      this.rank[rootX]++;
    }
  }

  // connected reports whether x and y are in the same set.
  connected(x: number, y: number): boolean {
    return this.find(x) === this.find(y);
  }
}
