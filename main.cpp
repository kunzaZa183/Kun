#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;
double arr[maxn][maxn] = {};
double dp[1 << maxn] = {};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            arr[i][j] /= 100;
        }
    vector<vector<int>> cur(n + 1);
    for (int i = 0; i < (1 << n); i++)
    {
        int ct = 0;
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                ct++;
        cur[ct].push_back(i);
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++)
        for (auto a : cur[i])
            for (int k = 0; k < n; k++)
                if (((1 << k) & a) == 0)
                    dp[(1 << k) | a] = max(dp[(1 << k) | a], dp[a] * arr[i][k]);
    cout << fixed << setprecision(12) << dp[(1 << n) - 1] * 100 << '\n';
}