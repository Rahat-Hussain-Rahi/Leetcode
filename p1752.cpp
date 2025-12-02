#include<iostream>
#include<vector>
using namespace std;
bool check(vector<int>& nums)
{
    int n=nums.size();
    int i{};
    for(;i<n-1;++i)
    {
        if(nums[i]>nums[i+1])
        {
            break;
        }
    }
    if(i==n-1)
    {
        return true;
    }
    ++i;

    int count=i;
     for(;i<n-1;++i)
    { 
        if(nums[i]>nums[i+1])
        {
            break;
        }
    }
    vector<int> arr(n);
    if(i==n-1)
    {
        int j{};
        while(j<n)
        {
            arr[j]=nums[count%n];
            count++;
            ++j;
        }

    }
    else
    {
        return false;
    }
    int k{};
    while(k<n-1)
    {
        if(arr[k]>arr[k+1])
        {
            return false;
        }
        ++k;
    }
    return true;


}

//[3,6,10,1,8,9,9,8,9]
int main()
{
    const int size{9};
    vector<int> arr(size);
    for(int i{};i<size;++i)
    {
        cin>>arr[i];

    }
    cout<<check(arr);
    return 0;
}