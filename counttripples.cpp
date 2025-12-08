#include<iostream>
using namespace std;
int countTriples(int n) 
{
    int count = 0;
    for (int a = 1; a <n-2; ++a) 
    {
        for (int b = a+1; b < n-1; ++b) 
        {
           for(int c=b+1; c <= n; ++c) 
            {
                if (a * a + b * b == c * c) 
                {
                    count+=2;
                }
            }
        }
    }
    return count;
    
}
int main() 
{
    int n = 5; // Example input
    int result = countTriples(n);
    cout << result << endl; // Output the result
    return 0;
}