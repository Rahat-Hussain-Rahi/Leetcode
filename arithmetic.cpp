#include<iostream>
#include<vector>    
#include<algorithm>
using namespace std;
bool canMakeArithmeticProgression(vector<int>& arr) 
    {
        sort(arr.begin(),arr.end());
        int diff=arr[1]-arr[0];
        int size=arr.size();
        for(int i{2};i<size;++i)
        {
            if((arr[i]-arr[i-1])!=diff)
            {
                return false;
            }
        }
        return true;
        
    }