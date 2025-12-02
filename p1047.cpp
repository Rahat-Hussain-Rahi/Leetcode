#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;
class Solution {
public:
    string removeDuplicates(string s) 
    {
        stack<char> stk;
        for(char ch:s)
        {
            if(!stk.empty()&&ch!=stk.top())
            {
                stk.push(ch);
            }
            else if(!stk.empty())
            {
                stk.pop();
            }
            else
            {
                stk.push(ch);
            }
        }
        string str;
        while(!stk.empty())
        {
            str+=stk.top();
            stk.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};