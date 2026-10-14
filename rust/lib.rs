//! DSA patterns in Rust. Each pattern is a module in its own folder.

// the solutions walk arrays by index on purpose, to show the pattern
#![allow(clippy::needless_range_loop)]
// a pattern's namesake problem lives in a file named after the pattern
#![allow(clippy::module_inception)]
// `n % 2 == 0` is how the problems are usually written
#![allow(clippy::manual_is_multiple_of)]

pub mod backtracking;
pub mod bitwisexor;
pub mod cyclicalsort;
pub mod fastandslowpointers;
pub mod fibnum;
pub mod graphs;
pub mod greedy;
pub mod hashmaps;
pub mod islandtraversal;
pub mod knapsackdp;
pub mod kwaymerge;
pub mod levelordertraversal;
pub mod mergeintervals;
pub mod misc;
pub mod modifiedbinarysearch;
pub mod monotonicstack;
pub mod orderedset;
pub mod palindromicsubsequence;
pub mod reverselinkedlist;
pub mod slidingwindow;
pub mod stack;
pub mod subsets;
pub mod topkelements;
pub mod topologicalsort;
pub mod treebfs;
pub mod treedfs;
pub mod trie;
pub mod twoheaps;
pub mod twopointers;
pub mod unionfind;
