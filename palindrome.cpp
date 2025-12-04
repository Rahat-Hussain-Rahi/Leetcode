#include<iostream>
using namespace std;
bool isPalindrome(int n)
{
    int original = n, reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return original == reversed;
}
int main()
{
    cout << "Enter the number: " << endl;
    int n;
    cin >> n;
    if (isPalindrome(n)) {
        cout << n << " is a palindrome." << endl;
    } else {
        cout << n << " is not a palindrome." << endl;
    }
    return 0;
}