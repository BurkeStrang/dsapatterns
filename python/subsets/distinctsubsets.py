"""
example1: [1,3] => [[], [1], [3], [1,3]]
example2: [1,5,3] => [[], [1], [5], [3], [1,5], [1,3], [5,3], [1,5,3]]
"""


def find_subsets(nums: list[int]) -> list[list[int]]:
    # start by adding the empty subset
    subsets: list[list[int]] = [[]]
    # subsets = [[]]
    for current_number in nums:
        # ===== Iteration 1 =====
        # current_number = 1
        # ===== Iteration 2 =====
        # current_number = 3

        # we will take all existing subsets and insert the current number in
        # them
        n = len(subsets)
        for i in range(n):
            # -------- EXAMPLE WALKTHROUGH --------
            # INPUT: nums = [1,3]
            # Before any loops:
            # subsets = [[]]

            # ===============================
            # OUTER LOOP 1
            # current_number = 1
            # n = 1
            #
            # INNER LOOP:
            #
            # i = 0
            # subsets[i] = []
            # subset (copy of subsets[i]) = []
            # after append current_number:
            # subset = [1]
            #
            # subsets becomes:
            # [[], [1]]
            # ===============================

            # ===============================
            # OUTER LOOP 2
            # current_number = 3
            # n = 2  (because subsets now has 2 items)
            #
            # INNER LOOP:
            #
            # i = 0
            # subsets[0] = []
            # subset = []
            # after append:
            # subset = [3]
            #
            # subsets becomes:
            # [[], [1], [3]]
            #
            # i = 1
            # subsets[1] = [1]
            # subset = [1]
            # after append:
            # subset = [1,3]
            #
            # subsets becomes:
            # [[], [1], [3], [1,3]]
            # ===============================
            subset = [*subsets[i], current_number]
            subsets.append(subset)
    return subsets
