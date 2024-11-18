#include <iostream>
using namespace std;

// Problem: Single Number
// Problem Description: Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

// You must implement a solution with a linear runtime complexity and use only constant extra space.

// Example 1:
// makefile
// Copy code
// Input: nums = [2,2,1]
// Output: 1
// Example 2:
// makefile
// Copy code
// Input: nums = [4,1,2,1,2]
// Output: 4
// Example 3:
// makefile
// Copy code
// Input: nums = [1]
// Output: 1
// Constraints:
// 1 <= nums.length <= 3 * 10^4
// -3 * 10^4 <= nums[i] <= 3 * 10^4
// Each element in the array appears twice except for one element which appears only once.

int main()
{
    // we will use bit manipulation XOR
    int num[5] = {4, 2, 1, 2, 1};
    int ans = 0;
    for (auto N : num)
    {
        ans ^= N;
    }

    cout << ans;

    cout << endl;
    return 0;
}