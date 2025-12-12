#include <iostream>
#include <vector>
using namespace std;
bool validMountainArray(vector<int> &arr)
{

    int len = arr.size();
    if (len < 3)
        return false;
    int maxidx = 0;
    for (int i = 1; i < len; ++i)
    {
        if (arr[i] > arr[maxidx])
        {
            maxidx = i;
        }
    }
    if ((maxidx == len - 1) || (maxidx == 0))
        return false;
    for (int i = maxidx; i < len - 1; ++i)
    {
        if (arr[i + 1] >= arr[i])
        {
            return false;
        }
    }
    for (int i = 0; i < maxidx; ++i)
    {
        if (arr[i + 1] <= arr[i])
        {
            return false;
        }
    }

    return true;
}
int main()
{

    int size;
    cout << "Enter the size";
    cin >> size;
    vector<int> arr(size, 0);
    for (int i{}; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << validMountainArray(arr);
    return 0;
}