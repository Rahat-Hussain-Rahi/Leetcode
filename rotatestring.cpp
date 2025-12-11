#include <iostream>
using namespace std;
bool rotateString(string s, string goal)
{
    if (s == goal)
    {
        return true;
    }
    int size = s.length();
    string original = s;
    for (int j{}; s[j] != '\0'; j++)
    {
        char first = s[0];
        int i{};
        for (; i < size - 1; ++i)
        {
            s[i] = s[i + 1];
        }
        s[i] = first;
        if (s == goal)
        {
            return true;
        }
        else if (s == original)
        {
            return false;
        }
    }
    return false;
}
int main()
{
}