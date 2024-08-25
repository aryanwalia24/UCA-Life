#include <iostream>
#include <algorithm>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> strings = {"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"};
    unordered_map<string, vector<string>> groups;
    vector<vector<string>> ans;

    for (string s : strings)
    {
        string origin;
        for (int i = 1; i < s.size(); i++)
        {
            int diff = (s[i] - s[i - 1] + 26) % 26;
            origin += to_string(diff);
        }
        groups[origin].push_back(s);
    }
    for (auto i : groups)
    {
        ans.push_back(i.second);
    }
    for (vector<string> s : ans)
    {
        cout<<"[ ";
        for (string c : s)
        {
            cout << c << " ";
        }
        cout<<"] ";
    }

    return 0;
}