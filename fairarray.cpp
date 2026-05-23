
#include <iostream>
#include <vector>
using namespace std;

int waysToMakeFair(vector<int>& nums)
{
    int n = nums.size();

    vector<int> preEven(n + 1, 0), preOdd(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        preEven[i + 1] = preEven[i];
        preOdd[i + 1] = preOdd[i];

        if (i % 2 == 0)
            preEven[i + 1] += nums[i];
        else
            preOdd[i + 1] += nums[i];
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int even = preEven[i] + (preOdd[n] - preOdd[i]);
        int odd  = preOdd[i] + (preEven[n] - preEven[i]);

        if (i % 2 == 1)
            swap(even, odd);

        if (even == odd)
            count++;
    }

    return count;
}
int main()
{
    vector<int> nums{1,1,1};
    cout << waysToMakeFair(nums) << endl;
    return 0;
}