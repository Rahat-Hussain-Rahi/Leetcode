#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<cmath>
using namespace std;
vector<bool> prefixesDivBy5(vector<int>& nums) 
    {
        int size=nums.size();
        vector<bool> vec(size,false);
         int num=0;
        for(int i{};i<size;++i)
        {
            num = ((num * 2) + nums[i]) % 5;
            if (num == 0) {
                vec[i] = true;
            }
        }
        return vec;
    }
int main()
{
   
    int size{};
    cout<<"ENter the size of test case :"<<endl;
    cin>>size;
     vector<int> vec(size,0);
    for(int i{};i<size;++i)
    {
        cin>>vec[i];
    }

    vector<bool> arr=prefixesDivBy5(vec);
    cout<<endl;
    for(bool val:arr)
    {
        cout<<val;
    }
    return 0;

}
