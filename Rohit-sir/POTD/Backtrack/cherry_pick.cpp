#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

void dfs(int i, int j, vector<vector<char>> arr, int sum, int &ans)
{
    if (i < 0 || j < 0 || i >= arr.size() || j >= arr[0].size() || arr[i][j] == 'x')
    {
        return;
    }
    if (i == arr.size() - 1 && j == arr[0].size() - 1)
    {
        ans = max(ans, sum);
        return;
    }
    if (arr[i][j] == '1')
    {
        sum++;
    }

    char t = arr[i][j];
    arr[i][j] = 'x';
    dfs(i + 1, j, arr, sum, ans);
    dfs(i, j + 1, arr, sum, ans);
    arr[i][j] = t;
}

int main()
{
    vector<vector<char>> arr = {{'s', '0', 'x', 'x'},
                                {'1', '0', 'x', 'x'},
                                {'x', '1', '1', '1'},
                                {'x', 'x', '1', 'e'}};

    int ans = INT_MIN;
    dfs(0, 0, arr, 0, ans);
    cout << ans;
    return 0;
}