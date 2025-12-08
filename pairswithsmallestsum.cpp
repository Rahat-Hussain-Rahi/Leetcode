// Q2. Find K Pairs with Smallest Sums
// You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.
// Define a pair (u, v) which consists of one element from the first array and one element from the second array.
// Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.
// Example 1:

// Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
// Output: [[1,2],[1,4],[1,6]]
// Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
// Example 2:

// Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
// Output: [[1,1],[1,1]]
// Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]

#include<iostream>
#include<vector>
using namespace std;
 vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> arr(k);
        int sum{},p1{},p2{},t{};
        int size1=nums1.size();
        int size2=nums2.size();
        for(int i{};i<size2;++i)
        {
            p1=nums1[i];
            p2=nums2[0];
            int j{};
            for(;j<size1;++j)
            {
                if((nums2[i]+nums1[j])<(p1+p2))
                {
                    p1=nums1[j];
                    p2=nums2[i];
                }
            }
            if(t<k)
            {
                arr[t].push_back(p1);
                arr[t].push_back(p2);
                ++t;
            }
            else
            {
                break;
            }
           
        }
        return arr;
    }
int main()
{
    vector<int>nums1={1,7,11};
    vector<int>nums2={2,4,6};
    int k=3;
    vector<vector<int>>result=kSmallestPairs(nums1,nums2,k);
    for(auto &pair:result)
    {
        cout<<"["<<pair[0]<<","<<pair[1]<<"] ";
    }
    return 0;
}