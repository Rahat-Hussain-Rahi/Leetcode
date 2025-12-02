#include<iostream>
#include<vector>
using namespace std;
int totalSteps(vector<int>& nums) 
    {
        int n=nums.size();
        int count=0;
        int i{};
        while(i<n-1)
        {
            if(nums[i]>nums[i+1])
            {
                for( int j=i+1;j<n-1;++j)
                {
                    nums[j]=nums[j+1];
                }
               ++count;
            }
            else
            {
                ++i;

            }
        }
        //[4,5,7,7,13]
        //[5,3,4,4,7,3,6,11,8,5,11]
        //[10,1,2,3,4,5,6,1,2,3]
    if(count!=0)
    {
        return count-1;
    }
        return count;
    }

    int main()
    {
        int size;
        cin>>size;
        vector<int> nums(size);
        for(int i{};i<size;++i)
        {
            cin>>nums[i];
        }    
        cout<<totalSteps(nums);
        return 0;
    }