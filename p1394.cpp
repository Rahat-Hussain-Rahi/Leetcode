#include<iostream>
#include<vector>
using namespace std;
int findLucky(int* arr,int size) 
    {
        if(size!=0)
        {
            int max=arr[0];
            int i=1;
            int n=size;
            while(i<n)
            {
                if(arr[i]>max)
                {
                    max=arr[i];
                }
                ++i;
            }
            vector<int> count(max+1);
            int j=0;
            while(j<n)
            {
                ++count[arr[j]];
                ++j;
            }

            int lucky=-1;
            int k=0;
            while(k<n)
            {
                if(arr[k]==count[arr[k]])
                {
                    if(arr[k]>lucky)
                    {
                        lucky=arr[i];
                    }

                }
                ++k;
            }

            return lucky;
        }
        return -1;
        
    }

    int main()
    {
        int size;
        cin>>size;
        int *arr=new int [size];
        for(int i{};i<size;++i)
        {
            cin>>arr[i];

        }

        cout<<findLucky(arr,size);
        return 0;
    }