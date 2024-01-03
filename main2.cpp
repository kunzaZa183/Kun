#include <bits/stdc++.h>
using namespace std;
const int maxn = 350, BIGNUM = 1000000000;
int dp[maxn + 1][maxn + 1], qsum[maxn + 1], trace[maxn + 1][maxn + 1];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> qsum[i];
    sort(qsum + 1, qsum + n + 1);
    for (int i = 1; i <= n; i++)
        qsum[i] += qsum[i - 1];
    for (int j = 1; j <= n; j++)
    {
        dp[1][j] = qsum[j] * (j - 1);
        trace[1][j] = 0;
    }
    for (int i = 2; i <= m * 2; i++)
        if (i <= m)
        {
            for (int j = i; j <= n; j++)
            {
                dp[i][j] = BIGNUM;
                for (int k = i - 1; k <= j; k++)
                {
                    int tmp = dp[i - 1][k] + (qsum[j] - qsum[k]) * (j - k - 1);
                    if (tmp < dp[i][j])
                    {
                        dp[i][j] = tmp;
                        trace[i][j] = k;
                    }
                }
            }
        }
        else
        {
            for (int j = i; j <= n; j++)
            {
                dp[i][j] = BIGNUM;
                for (int k = i - 1; k <= j; k++)
                {
                    int goback = 2 * (i - m - 1);
                    int tmpi = i - 1, tmpj = k;
                    while (goback--)
                    {
                        tmpj = trace[tmpi][tmpj];
                        tmpi--;
                    }
                    int add = dp[i - 1][k] + (qsum[j] - qsum[k]) * (j - k - 1) + 2 * (j - k) * (tmpj - trace[tmpi][tmpj]);
                    if (add < dp[i][j])
                    {
                        dp[i][j] = add;
                        trace[i][j] = k;
                    }
                }
            }
        }
    cout << dp[2 * m][n] << '\n';
}