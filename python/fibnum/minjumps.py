"""
Given an array of positive numbers,
where each element represents the max number of jumps that can be made
forward from that element,
write a program to find the minimum number of jumps needed to reach the end
of the array
(starting from the first element).
If an element is 0, then we cannot move through that element.

Example 1:
Input = {2,1,1,1,4}
Output = 3
Explanation: Starting from index '0', we can reach the last index through:
0->2->3->4

Example 2:
Input = {1,1,3,6,9,3,0,1,3}
Output = 4
Explanation: Starting from index '0', we can reach the last index through:
0->1->2->3->8
"""


def count_min_jumps_recursive(
    jumps: list[int], current_index: int
) -> int | None:
    last = len(jumps) - 1
    # if we have reached the last index, we don't need any more jumps
    if current_index >= last:
        return 0

    # jumps[current_index] == 0 gives an empty range below: we can't move
    # through this element
    total_jumps: int | None = None
    start = current_index + 1
    end = min(current_index + jumps[current_index], last)
    # try every jump we can make from here and keep the best one
    for next_index in range(start, end + 1):
        min_jumps = count_min_jumps_recursive(jumps, next_index)
        if min_jumps is None:
            continue
        if total_jumps is None or min_jumps + 1 < total_jumps:
            total_jumps = min_jumps + 1
    return total_jumps


def count_min_jumps(jumps: list[int]) -> int | None:
    """Returns None if the end of the array can't be reached."""
    return count_min_jumps_recursive(jumps, 0)
