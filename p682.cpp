#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int calPoints(vector<string>& operations) 
    {
        long long sum{};
        stack<long long> stk;
        long long result{};
        for(string ch : operations)
        {
            if(ch=="C")
            {
                result-=stk.top();
                stk.pop();
               
            }
            else if(ch=="D")
            {

                long long val=stk.top()*2;
                result+=val;
                stk.push(val);
            }
            else if(ch=="+")
            {
                long long num1=stk.top();
                stk.pop();
                long  num2=stk.top();
               long sum=num1+num2;
                result+=sum;
                stk.push(num1);
                stk.push(sum);
            }
            else
            {
                result+=stoi(ch);
                stk.push(stoi(ch));
            }

        }
        return result;
    }
};