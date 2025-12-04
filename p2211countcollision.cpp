#include<iostream>
using namespace std;
 int countCollisions(string str) {
        int count{};
        for(int i{1};str[i]!='\0';++i)
        {
           if(str[i]=='L'&&str[i-1]=='S')
           {
                ++count;
                str[i]='S';
           }
           else if(str[i]=='S'&&str[i-1]=='R')
           {
                ++count;
                str[i-1]='S';
           }
           else if(str[i]=='L'&&str[i-1]=='R')
           {
            count+=2;
            str[i]='S';
            str[i-1]='S';
           }
        }
        int size=str.length();
        for(int i{size-1};i>0;--i)
        {
           if(str[i]=='L'&&str[i-1]=='S')
           {
                ++count;
                str[i]='S';
           }
           else if(str[i]=='S'&&str[i-1]=='R')
           {
                ++count;
                str[i-1]='S';
           }
           else if(str[i]=='L'&&str[i-1]=='R')
           {
            count+=2;
            str[i]='S';
            str[i-1]='S';
           }
        }
        return count;
    }
int main(){
    cout<<"Enter the directions string: "<<endl;
    string str;
    cin>>str;
    cout<<"The number of collisions is: "<<countCollisions(str)<<endl;
    return 0;
}