#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool isValid(string s) 
{
        stack<char> stk;
        for(char ch:s)
        {
            if(ch=='(' || ch=='{' || ch=='[')
            {
                stk.push(ch);
            }
            else
            {
                if(stk.empty()) return false;
                char top=stk.top();
                stk.pop();
                if((ch==')' && top!='(') || (ch=='}' && top!='{') || (ch==']' && top!='['))
                {
                    return false;
                }
            }
        }
        return true;

}
int main()
{
    string s;
    cout<<"Enter a string of parentheses: ";
    cin>>s;
    if(isValid(s))
    {
        cout<<"The parentheses are valid."<<endl;
    }
    else
    {
        cout<<"The parentheses are not valid."<<endl;
    }
    return 0;
}