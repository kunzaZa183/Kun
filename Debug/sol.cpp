#include <bits/stdc++.h>
using namespace std;
#define int long long
const string sth = "ACGT";
const int MOD = 1000000007, maxn = 100000;
int dp[maxn][4][4][4] = {}; // cur, first of second to last, first last, last last
int conv(char c)
{
    for (int i = 0; i < 4; i++)
        if (sth[i] == c)
            return i;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string s;
    cin >> s;
    if (s.front() == '?')
    {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                dp[0][j][i][i] = 1;
    }
    else
        for (int i = 0; i < 4; i++)
            dp[0][i][conv(s.front())][conv(s.front())] = 1;
    for (int i = 0; i < s.size() - 1; i++)
        if (s[i + 1] == '?')
        {
            for (int j = 0; j < 4; j++)
                for (int k = 0; k < 4; k++)
                    for (int l = 0; l < 4; l++)
                    {
                        if (l == j)
                            for (int m = 0; m < 4; m++)
                                dp[i + 1][k][m][m] = (dp[i + 1][k][m][m] + dp[i][j][k][l]) % MOD;
                        for (int m = 0; m < 4; m++)
                            if (m != l)
                                dp[i + 1][j][k][m] = (dp[i + 1][j][k][m] + dp[i][j][k][l]) % MOD;
                    }
        }
        else
        {
            for (int j = 0; j < 4; j++)
                for (int k = 0; k < 4; k++)
                    for (int l = 0; l < 4; l++)
                    {
                        int x = conv(s[i + 1]);
                        if (l == j)
                            dp[i + 1][k][x][x] = (dp[i + 1][k][x][x] + dp[i][j][k][l]) % MOD;
                        if (x != l)
                            dp[i + 1][j][k][x] = (dp[i + 1][j][k][x] + dp[i][j][k][l]) % MOD;
                    }
        }
    int sum = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            sum = (sum + dp[s.size() - 1][i][j][i]) % MOD;
    cout << sum << "\n";
}