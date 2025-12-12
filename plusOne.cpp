#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> plusOne(vector<int> &digits)
{
    stack<int> stk;
    for (int val : digits)
    {
        stk.push(val);
    }
    int sum = stk.top() + 1;
    int remainder = 0;
    if (sum >= 10)
    {
        sum = sum % 10;
        remainder = 1;
    }
    stk.pop();
    vector<int> result;
    result.push_back(sum);
    while (!stk.empty())
    {
        sum = stk.top() + remainder;
        if (sum >= 10)
        {
            sum = sum % 10;
            remainder = 1;
        }
        else
        {
            remainder = 0;
        }
        result.push_back(sum);
        stk.pop();
    }
    if (remainder != 0)
    {
        result.push_back(remainder);
    }
    reverse(result.begin(), result.end());
    return result;
}