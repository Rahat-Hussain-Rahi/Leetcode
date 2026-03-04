#include <iostream>
#include <vector>
using namespace std;
int numSpecial(vector<vector<int>> &mat)
{
    int len = mat.size();
    bool status{true};
    int count{};
    for (int row{}; row < len; ++row)
    {
        status=true;
        for (int col{}; col < mat[row].size(); ++col)
        {
            if (mat[row][col] == 1)
            {
                int k{};
                while (k < len)
                {
                    if (k != row && mat[k][col] == 1)
                    {
                        status=false;
                        break;
                    }
                    ++k;
                }
                int j = col + 1;
                while (j < mat[row].size())
                {
                    if (mat[row][j] == 1)
                    {
                       
                        status=false;
                        break;
                    }
                    ++j;
                }
                if (status)
                {
                    cout<<k<<' '<<j<<endl;
                    ++count;
                    break;
                }
            }
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> arr(4);
    arr[0]={0,1,0};
    arr[1]={0,0,0};
    arr[2]={0,0,1};
    arr[3]={1,0,0};
    cout<<numSpecial(arr);
    return 0;
}