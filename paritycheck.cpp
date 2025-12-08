#include<iostream>
using namespace std;
void paritycheck(int l,int r)
{
    long long x{};
    while (l<=r)
    {
        x=x^l;
        l++;
    }
    if(x%2==0)
    {
        cout<<"Even"<<endl;
    }
    else
    {
        cout<<"Odd"<<endl;
    }
}
int main() 
{
    int l = 3, r = 5; // Example input
    paritycheck(l, r);
    return 0;
}
    