"""
Given a set of investment projects with their respective profits, we need
to find the most profitable projects. We are given an initial capital and
are allowed to invest only in a fixed number of projects. Our goal is to
choose projects that give us the maximum profit. We can start an investment
project only when we have the required capital. Once a project is selected,
we can assume that its profit has become our capital.
"""

import heapq


def find_maximum_capital(
    capital_arr: list[int],
    profits_arr: list[int],
    number_of_projects: int,
    initial_capital: int,
) -> int:
    # a min-heap of (capital, project index), so the cheapest project is on
    # top
    min_capital_heap: list[tuple[int, int]] = []
    # a max-heap of the profits of the projects we can afford; heapq only
    # makes min-heaps, so the profits are stored negated
    max_profit_heap: list[int] = []

    # insert all project indices into the min-capital heap
    for i, capital in enumerate(capital_arr):
        heapq.heappush(min_capital_heap, (capital, i))

    # try to find a total of 'number_of_projects' best projects
    available_capital = initial_capital
    for _ in range(number_of_projects):
        # move all affordable projects into the max-profit heap
        while min_capital_heap and min_capital_heap[0][0] <= available_capital:
            _, i = heapq.heappop(min_capital_heap)
            heapq.heappush(max_profit_heap, -profits_arr[i])

        # terminate if we are not able to find any project that can be
        # completed within the available capital
        if not max_profit_heap:
            break

        # select the project with the maximum profit
        available_capital += -heapq.heappop(max_profit_heap)

    return available_capital
