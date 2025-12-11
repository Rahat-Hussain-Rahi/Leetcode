#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int notevenmaxsum(int size,vector<int>& arr)
{
    int sum{};
    for(int i{};i<size;++i)
    {
        sum+=arr[i];
    }
    if(sum%2==1)
    {
        return sum;
    }
    else
    {
        sort(arr.begin(),arr.end());
        for(int i{};i<size;++i)
        {
            sum-=arr[i];
            if(sum%2==1)
            {
                return sum;
            }
            sum+=arr[i];
        }
    }
    return sum;
}
int main()
{
    int size{};
    cin>>size;
    vector<int> arr(size);
    for(int i{};i<size;++i)
    {
        cin>>arr[i];
    }
    int result=notevenmaxsum(size,arr);
    cout<<result<<endl;
    return 0;
}
