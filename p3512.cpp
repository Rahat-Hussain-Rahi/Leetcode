#include<iostream>
#include<vector>
using namespace std;
int minOperations(vector<int>& nums, int key) 
    {
        int size=nums.size();
        int sum{};
        for(int i{};i<size;++i)
        {
            sum+=nums[i];
        }
            return (sum%key);
    
    }

int main()
{
    vector<int>nums={3,2,20,5,1,3};
    int key=10;
    cout<<minOperations(nums,key);
    return 0;
}