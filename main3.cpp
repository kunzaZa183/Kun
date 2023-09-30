#include <bits/stdc++.h>
using namespace std;
const int maxn = 5001;
int dp[maxn], freq[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--)
    {
        int n;
        cin >> n;
        memset(freq, 0, sizeof freq);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x < maxn)
                freq[x]++;
        }
        int mex;
        for (int i = 0; i < maxn; i++)
            if (freq[i] == 0)
            {
                mex = i;
                break;
            }
        fill(dp, dp + maxn, INT_MAX);
        dp[mex] = 0;
        for (int i = mex; i >= 0; i--)
            for (int j = 0; j < i; j++)
                dp[j] = min(dp[j], dp[i] + (freq[j] - 1) * i + j);
        cout << dp[0] << "\n";
    }
}