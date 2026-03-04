#include <iostream>
#include <vector>
using namespace std;
void rotate1(vector<int> &nums, int k)
{
    //O(n*k)
    int i{1};
    int len = nums.size();
    k%=len;
    while (i <= k)
    {
        int last = nums[len - 1];
        for (int j = len - 1; j > 0; --j)
        {
            nums[j] = nums[j - 1];
        }
        nums[0] = last;
        ++i;
    }
}
void rotate2(vector<int> &nums, int k)
{//O(n)
    int len=nums.size();
    k=k%len;
    reverse(nums.begin(),nums.end());
    reverse(nums.begin(),nums.begin()+k);
    reverse(nums.begin()+k,nums.end());
}