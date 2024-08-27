#include <iostream>
#include <vector>
using namespace std;

vector<vector<string>> ans;
void dfs(int i, int j, int m, int n, vector<vector<char>> &arr)
{
    if (i == m - 1 && j == n - 1)
    {
        cout << (to_string(i) + "," + to_string(j)) << endl;
        return;
    }
    cout << (to_string(i) + "," + to_string(j)) << " -> ";

    if (i + 1 < m && arr[i + 1][j] == '0')
    {
        dfs(i + 1, j, m, n, arr);
    }

    if (j + 1 < n && arr[i][j + 1] == '0')
    {
        dfs(i, j + 1, m, n, arr);
    }
}
int main()
{
    vector<vector<char>> arr = {
        {'0', '0', '0'},
        {'0', '0', '0'},
        {'0', '0', '0'}};
    int m = arr.size();
    int n = arr[0].size();
    dfs(0, 0, m, n, arr);
    return 0;
}
