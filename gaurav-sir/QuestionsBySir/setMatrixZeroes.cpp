#include <iostream>
#include <vector>
using namespace std;
// Approach 1
// DO it in Constant Space

// Approach 2
// Using Bit manipulation

void setZeroes(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    bool r = false, c = false;
    for (int i = 0; i < m; i++)
    {
        if (matrix[0][i] == 0)
        {
            r = true;
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][0] == 0)
        {
            c = true;
            break;
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        if (matrix[i][0] == 0)
        {
            for (int j = 1; j < m; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < m; i++)
    {
        if (matrix[0][i] == 0)
        {
            for (int j = 1; j < n; j++)
            {
                matrix[j][i] = 0;
            }
        }
    }

    if (r)
    {
        for (int i = 0; i < m; i++)
        {
            matrix[0][i] = 0;
        }
    }
    if (c)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i][0] = 0;
        }
    }
}

int main()
{
    /*
Input: matrix = [1,1,1]
                [1,0,1]
                [1,1,1]

        Output: [1,0,1]
                [0,0,0]
                [1,0,1]

Input: matrix = [0,1,2,0]
                [3,4,5,2]
                [1,3,1,5]

Output:         [0,0,0,0]
                [0,4,5,0]
                [0,3,1,0]
*/
    return 0;
}