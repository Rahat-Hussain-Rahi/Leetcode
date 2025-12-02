#include<iostream>
#include<string> 
using namespace std;

bool vowel(char c)
{
    string v="AEIOUaeiou";
    int low=0;
    int high=v.length()-1;
    int i{};
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(v[mid]==c)
        {
            return true;
        }
        else if(v[mid]<c)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return false;
}
bool consonant(char c)
{
    string arr="BCDFGHJKLMNPQRSTVWXYZbcdfghjklmnpqrstvwxyz";
   int low=0;
    int high=arr.length()-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]==c)
        {
            return true;
        }
        else if(arr[mid]<c)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return false;
}
bool special(char c)
{
  string str="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  int low=0;
    int high=str.length()-1;
    int i{};
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(str[mid]==c)
        {
            return false;
        }
        else if(str[mid]<c)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
        
    } 
    return true;
}
    bool isValid(string word) 
    {
        bool Vowel=false;
        bool Consonant=false;
        bool Special=false;
        if(word.length()>=3)
        {
            int i{};
            while(word[i]!='\0')
            {
                if(Vowel!=true)
                Vowel=vowel(word[i]);
                else if(Consonant!=true)
                Consonant=consonant(word[i]);
                else if(Special==false)
                {
                    Special=special(word[i]);
                    if(Special)
                    {
                        return false;
                    }
                }
                ++i;
            }
            
            return Vowel && Consonant;
        }
        return false;
        
    }
int main()
{
    string s1="b3";
    string s2="Aav#";
    string s3="Aaaa";
    string s4="2b";
    cout<<isValid(s4);
    cout<<endl;
    cout<<isValid(s2);
    cout<<endl;
    cout<<isValid(s3);
    return 0;
}