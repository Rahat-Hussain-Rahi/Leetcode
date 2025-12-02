#include<iostream>
using namespace std;

int smallestRepunitDivByK(int k) 
{
    int num{};
    int i{};
    for(;i<k;++i)
    {
        num= (num * 10 + 1) % k;
        if(num%k==0)
        {
            return i+1;
        }
    }
    if(num%k==0)
    {
        return i;
    }
    return -1;
    
}
int main()
{
    //Test Cases
    //t1 k=125
    //t2 k=1
    //t3 k=2
    //t4 k=5
}