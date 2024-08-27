#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int dfs(int i, int j, int m, int n, vector<vector<int>> &arr)
{
    if (i < 0 || i >= m || j < 0 || j >= n)
    {
        return 0;
    }
    if (i == m - 1 && j == n - 1)
    {
        return arr[i][j];
    }
    int choice1 = dfs(i + 1, j, m, n, arr);
    int choice2 = dfs(i, j + 1, m, n, arr);
    
    return arr[i][j] + max(choice1, choice2);
}
int main()
{
    vector<vector<int>> arr = {{1, 1, 1, 1},
                               {1, 1, 1, 1},
                               {1, 1, 1, 1},
                               {0, 0, 0, 0}};
    int m = arr.size();
    int n = arr[0].size();

    cout << dfs(0, 0, m, n, arr);
    return 0;
}
