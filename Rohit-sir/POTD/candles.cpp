#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int candies(vector<int> &rating)
{
    int n = rating.size();
    vector<int> candy(n, 1);
    for (int i = 1; i < n; i++)
    {
        if (rating[i] > rating[i - 1])
        {
            candy[i] = candy[i - 1] + 1;
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (rating[i] > rating[i + 1])
        {
            candy[i] = max(candy[i], candy[i + 1] + 1);
        }
    }

    int ans = accumulate(begin(candy), end(candy), 0);
    return ans;
}

int main()
{
    vector<int> nums = {1, 0, 2};
    int ans = candies(nums);
    cout << ans;
}