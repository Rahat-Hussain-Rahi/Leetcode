#include<iostream>
using namespace std;
int Find(int *arr,int size)
{
    int count=0;
    int i=1;
    while(i<size-1)
    {
        if((arr[i]>arr[i-1]&&arr[i]>arr[i+1])||(arr[i]<arr[i-1]&& arr[i]<arr[i+1]))
        {
            ++count;
        }
        ++i;
    }
   return count;
}
int main()
{
    const int size=5;
    int arr[size]{6,4,3,3,3};
    cout<<Find(arr,size);
    return 0;
}