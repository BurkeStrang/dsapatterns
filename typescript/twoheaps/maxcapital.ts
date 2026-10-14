// Given a set of investment projects with their respective profits, we need
// to find the most profitable projects. We are given an initial capital and
// are allowed to invest only in a fixed number of projects. Our goal is to
// choose projects that give us the maximum profit. We can start an investment
// project only when we have the required capital. Once a project is selected,
// we can assume that its profit has become our capital.

import { Heap } from "../common/heap.ts";

export function findMaximumCapital(
  capitalArr: number[],
  profitsArr: number[],
  numberOfProjects: number,
  initialCapital: number,
): number {
  // a min-heap of project indices, so the cheapest project is on top
  const minCapitalHeap = new Heap<number>(
    (a, b) => capitalArr[a] < capitalArr[b],
  );
  // a max-heap of the profits of the projects we can afford
  const maxProfitHeap = new Heap<number>((a, b) => a > b);

  // insert all project indices into the min-capital heap
  for (let i = 0; i < capitalArr.length; i++) {
    minCapitalHeap.push(i);
  }

  // try to find a total of 'numberOfProjects' best projects
  let availableCapital = initialCapital;
  for (let project = 0; project < numberOfProjects; project++) {
    // move all affordable projects into the max-profit heap
    let cheapest = minCapitalHeap.peek();
    while (cheapest !== undefined && capitalArr[cheapest] <= availableCapital) {
      maxProfitHeap.push(profitsArr[cheapest]);
      minCapitalHeap.pop();
      cheapest = minCapitalHeap.peek();
    }

    // terminate if we are not able to find any project that can be
    // completed within the available capital
    const profit = maxProfitHeap.pop();
    if (profit === undefined) {
      break;
    }

    // select the project with the maximum profit
    availableCapital += profit;
  }

  return availableCapital;
}
