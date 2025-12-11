#include <iostream>
using namespace std;
bool repeatedSubstringPattern(string s)
{ string str;
        int size=s.length();
        for(int i=0;i<size;++i)
        {
            str+=s[i];
            int k{};
            int j{i+1};
            for(;j<size;++j)
            {
               
                if(str[k]!=s[j])
                {
                    break;
                }
                k=(k+1)%str.length();
            }
            if(j==size&&k==0&&str.length()!=size)
            {
                return true;
            }
        }
        return false;
    }
int main()
{
    string str;
    cin>>str;
    cout<<repeatedSubstringPattern(str);
    return 0;
}