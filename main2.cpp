#include <bits/stdc++.h>
using namespace std;
const int maxn = 7;
int arr[maxn][maxn], second[maxn][maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    arr[0][0] = 1;
    for (auto a : s)
    {
        if (a == '?')
        {
            for (int i = 0; i < maxn; i++)
                for (int j = 0; j < maxn - 1; j++)
                    second[i][j + 1] += arr[i][j];
            for (int i = 0; i < maxn - 1; i++)
                for (int j = 0; j < maxn; j++)
                    second[i + 1][j] += arr[i][j];
            for (int i = 1; i < maxn; i++)
                for (int j = 0; j < maxn; j++)
                    second[i - 1][j] += arr[i][j];
            for (int i = 0; i < maxn; i++)
                for (int j = 1; j < maxn; j++)
                    second[i][j - 1] += arr[i][j];
        }
        else if (a == 'U')
            for (int i = 1; i < maxn; i++)
                for (int j = 0; j < maxn; j++)
                    second[i - 1][j] += arr[i][j];
        else if (a == 'R')
            for (int i = 0; i < maxn; i++)
                for (int j = 0; j < maxn - 1; j++)
                    second[i][j + 1] += arr[i][j];
        else if (a == 'L')
            for (int i = 0; i < maxn; i++)
                for (int j = 1; j < maxn; j++)
                    second[i][j - 1] += arr[i][j];
        else if (a == 'D')
            for (int i = 0; i < maxn - 1; i++)
                for (int j = 0; j < maxn; j++)
                    second[i + 1][j] += arr[i][j];

        for (int i = 0; i < maxn; i++)
            for (int j = 0; j < maxn; j++)
                arr[i][j] = second[i][j];
        memset(second, 0, sizeof second);
    }
    cout << arr[maxn - 1][0] << "\n";
}