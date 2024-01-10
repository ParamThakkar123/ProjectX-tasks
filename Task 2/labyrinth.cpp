#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

vector<vector<string>> ans;
vector<vector<string>> original;

int cmp = 0;

void dfs(int i, int j, int cnt, vector<vector<string>> &arr)
{
    int m = arr[0].size();
    for (int k = -1; k <= 1; k++)
    {
        for (int l = -1; l <= 1; l++)
        {
            if (k == 0 && l == 0)
                continue;
            int row = i + k, col = j + l;
            if (row > 4)
            {
                if (cnt + 1 > cmp)
                {
                    cmp = cnt + 1;
                    ans = arr;
                    ans[i][j] = to_string(cnt);
                }
            }
            else if (row >= 0 && col >= 0 && col < m && arr[row][col] == ".")
            {
                arr[i][j] = to_string(cnt);
                dfs(row, col, cnt + 1, arr);
                arr[i][j] = ".";
            }
        }
    }
}

int main()
{
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    vector<vector<string>> arr(5);
    for (auto &i : arr)
    {
        string temp;
        inFile >> temp;
        for (int j = 0; j < temp.size(); j++)
        {
            string cmp = "";
            cmp += temp[j];
            i.push_back(cmp);
        }
    }

    int m = arr[0].size();
    for (int i = 0; i < m; i++)
    {
        if (arr[0][i] == ".")
        {
            dfs(0, i, 0, arr);
        }
    }

    if (cmp == 0)
    {
        ans = arr; // Store the original grid
        original = arr;
    }

    if (cmp == 0)
    {
        outFile << -1 << endl;
        for (int i = 0; i < 5; i++)
        {
            for (auto j : original[i])
            {
                outFile << j << " ";
            }
            outFile << endl;
        }
    }
    else
    {
        outFile << cmp << endl;
        for (int i = 0; i < 5; i++)
        {
            for (auto j : ans[i])
            {
                outFile << j << " ";
            }
            outFile << endl;
        }
    }

    inFile.close();
    outFile.close();
    return 0;
}
