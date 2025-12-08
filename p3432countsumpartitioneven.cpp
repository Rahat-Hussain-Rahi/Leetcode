// p3432. Count Partitions with Even Sum Difference
// You are given an integer array nums of length n.
// A partition is defined as an index i where 0 <= i < n - 1, splitting the array into two non-empty subarrays such that:

// Left subarray contains indices [0, i].
// Right subarray contains indices [i + 1, n - 1].
// Return the number of partitions where the difference between the sum of the left and right subarrays is even.

// Example 1:

// Input: nums = [10,10,3,7,6]

// Output: 4

// Explanation:

// The 4 partitions are:

// [10], [10, 3, 7, 6] with a sum difference of 10 - 26 = -16, which is even.
// [10, 10], [3, 7, 6] with a sum difference of 20 - 16 = 4, which is even.
// [10, 10, 3], [7, 6] with a sum difference of 23 - 13 = 10, which is even.
// [10, 10, 3, 7], [6] with a sum difference of 30 - 6 = 24, which is even.
// Example 2:

// Input: nums = [1,2,2]

// Output: 0

// Constraints:

// 2 <= n == nums.length <= 100
// 1 <= nums[i] <= 100
#include <iostream>
#include <vector>
using namespace std;
 int countPartitions(vector<int>& nums) 
    {
        int count{},sum1{},sum2{};
        int size=nums.size();
        for(int i{};i<size-1;++i)
        {
            sum1+=nums[i];
            for(int  j=i+1;j<size;++j){
                sum2+=nums[j];
            }
            if((sum1-sum2)%2!=0)
            {
                ++count;
            }
            sum2=0;
        }
        return count;
        
}
int main()
{
    vector<int>nums={10,1,3,7,6};
    cout<<countPartitions(nums);
    return 0;
}