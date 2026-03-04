#include <iostream>
#include<unordered_set>
using namespace std;
bool isHappy(int n)
{
    unordered_set<int> seen;

    while (n != 1)
    {
        if (seen.count(n))
            return false;

        seen.insert(n);
        int sum = 0;

        while (n > 0)
        {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        n = sum;
    }
    return true;
}
int next(int n)
{
    int sum = 0;
    while (n > 0)
    {
        int d = n % 10;
        sum += d * d;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n)
{
    int slow = n;
    int fast = next(n);

    while (fast != 1 && slow != fast)
    {
        slow = next(slow);
        fast = next(next(fast));
    }
    return fast == 1;
}


int main()
{
    for(int i{1};i<10000000;++i)
    {
        if(!isHappy(i))
        {
            cout<<i<<endl;
        }
    }
    // cout<<isHappy(num);
    return 0;
}