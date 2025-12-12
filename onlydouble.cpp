#include<iostream>
#include<vector>
using namespace std;
vector<int> doublefrequency(vector<int> arr)
{
    int len=arr.size();
    vector<int> result;
    result.push_back(arr[0]);
    int k{};
    int pre{};
    for(int i{1};i<len;++i)
    {
        if(result[k]==arr[i]&&pre<1)
        {
            ++k;
            result.push_back(arr[i]);
            pre++;

        }
        else if(result[k]!=arr[i])
        {
            result.push_back(arr[i]);
            k++;
            pre=0;
        }
    }
    return result;
}
int main()
{
    int size;
    cout<<"Enter the size of array ";
    cin>>size;
    vector<int> arr(size,0);
    cout<<"\n Enter the element of array";
    for(int i{};i<size;++i)
    {
        cin>>arr[i];
    }
    vector<int> result=doublefrequency(arr);
    for(int i{};i<result.size();++i)
    {
        cout<<'\t'<<result[i];
    }
    return 0;
}