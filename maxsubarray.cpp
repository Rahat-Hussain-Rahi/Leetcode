#include<iostream>
#include<vector>    
#include<climits>
using namespace std;
long maxSubarrayValue(vector<int> arr) 
{
    long long sum=LLONG_MIN;
    long long even_sum{},odd_sum{};
    long long val=0;
    int len=arr.size();
    for(int i{};i<len;++i)
    {
        even_sum=0;
        odd_sum=0;
        for(int j{i};j<len;++j)
        {
            // int relative_index = j - i;
            if(j%2==0)
            {
                even_sum+=arr[j];
            }
            else
            {
                odd_sum+=arr[j];
            }
            val=(even_sum-odd_sum)*(even_sum-odd_sum);
            if(val>=sum)
            {
                sum=val;
            }
        }
    }
    return sum;
    
}
int main()
{
    vector<int>arr={-1, -4, 2};
    long long result=maxSubarrayValue(arr);
    cout<<result;
    return 0;
}