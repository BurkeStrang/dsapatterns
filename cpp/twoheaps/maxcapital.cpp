#include <functional>
#include <queue>
#include <utility>
#include <vector>

// Given a set of investment projects with their respective profits, we need
// to find the most profitable projects. We are given an initial capital and
// are allowed to invest only in a fixed number of projects. Our goal is to
// choose projects that give us the maximum profit. We can start an investment
// project only when we have the required capital. Once a project is selected,
// we can assume that its profit has become our capital.

int find_maximum_capital(const std::vector<int> &capital_arr,
                         const std::vector<int> &profits_arr,
                         int number_of_projects, int initial_capital)
{
    int n = std::ssize(profits_arr);
    // a min-heap of (capital, project index), so the cheapest project is on
    // top; std::greater turns the max-heap into a min-heap
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<>>
        min_capital_heap;
    // a max-heap of the profits of the projects we can afford
    std::priority_queue<int> max_profit_heap;

    // insert all project indices into the min-capital heap
    for (int i = 0; i < n; i++)
    {
        min_capital_heap.push({capital_arr[i], i});
    }

    // try to find a total of 'number_of_projects' best projects
    int available_capital = initial_capital;
    for (int project = 0; project < number_of_projects; project++)
    {
        // move all affordable projects into the max-profit heap
        while (!min_capital_heap.empty() &&
               min_capital_heap.top().first <= available_capital)
        {
            max_profit_heap.push(profits_arr[min_capital_heap.top().second]);
            min_capital_heap.pop();
        }

        // terminate if we are not able to find any project that can be
        // completed within the available capital
        if (max_profit_heap.empty())
        {
            break;
        }

        // select the project with the maximum profit
        available_capital += max_profit_heap.top();
        max_profit_heap.pop();
    }

    return available_capital;
}
