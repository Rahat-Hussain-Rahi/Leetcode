#include<iostream>
using namespace std;
int pivot(int n)
{
    if(n==1)return n;
    int sum=n*((n+1))/2;
    for(int mid{n/2};mid<n;++mid)
    {
        int sum2=mid*((mid+1))/2;
        if((sum-sum2+mid)==sum2)
        {
            return mid;
        }
    }
    return -1;

}
int main()
{
    cout<<"ENter the number: "<<endl;
    int n;
    cin>>n;
    cout<<"The pivot number is: "<<pivot(n)<<endl;
    return 0;
}