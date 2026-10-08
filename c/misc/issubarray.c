#include <stdbool.h>
#include <string.h>

bool is_subarray
(
    const int *nums,
    int nums_len,
    const int *sub,
    int sub_len
)
{
    int n = sub_len;
    for (int i = 0; i + n <= nums_len; i++)
    {
        if (memcmp(nums + i, sub, (size_t)n * sizeof(int)) == 0)
        {
            return true;
        }
    }
    return false;
}
