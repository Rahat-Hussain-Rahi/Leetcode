#include <iostream>
#include <string>
using namespace std;
bool subStr(string key, string scr)
{
    if (scr.length() == key.length())
    {
        return scr==key;
    }

    for (int i = 0; scr[i] != '\0'; ++i)
    {
        int j = 0;
        for (; key[j] != '\0'; ++j)
        {
            if (scr[i+j] != key[j])
            {
                break;
            }
        }
        if (key[j] == '\0')
        {
            return true;
        }
    }
    return false;
}
int repeatedStringMatch(string a, string b)
{
    string repeat = a;
    int count = 1;
    while (repeat.length() < b.length())
    {
        ++count;
        repeat += a;
    }
    if (subStr(b, repeat))
    {
        return count;
    }
    else
    {
        repeat += a;
        ++count;
        if (subStr(b, repeat))
        {
            return count;
        }
    }
    cout << repeat << endl;
    return -1;
}
int main()
{
    string a = "abcd", b = "cdabcdab";
    cout << repeatedStringMatch(a, b);

    return 0;
}