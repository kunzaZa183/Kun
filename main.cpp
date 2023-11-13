#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000;
int arrend[maxn + 1];
vector<int> nums[maxn + 1];
int n, k;
int find_ans(int in)
{
    if (in >= n)
        return in;
    if (nums[in].size() <= k)
        return in;
    arrend[in] = find_ans(arrend[in]);
    return arrend[in];
}
const int maxm = 200000;
pair<int, int> alldays[maxm];
const int maxk = 10, logm = 20, verylow = -1000000000;
int dp[logm][maxn][maxk + 1]; // left, before number
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tests;
    cin >> tests;

    while (tests--)
    {
        int m;
        cin >> n >> m >> k;
        for (int i = 0; i < n; i++)
        {
            nums[i].clear();
            arrend[i] = i + 1;
        }

        for (int i = 0; i < m; i++)
        {
            cin >> alldays[i].first >> alldays[i].second;
            alldays[i].first--, alldays[i].second--;
            int l = alldays[i].first, r = alldays[i].second;
            while (l <= r)
            {
                nums[l].push_back(alldays[i].first);
                l = find_ans(l + 1);
            }
        }

        for (int i = 0; i < n; i++)
            sort(nums[i].begin(), nums[i].end());

        for (int i = 0; i < logm; i++)
            for (int j = 0; j < n; j++)
                for (int k2 = 0; k2 <= k; k++)
                    dp[i][j][k] = verylow;

        int ct = 0;
        for (int i = 0; i < n; i++)
            if (nums[i].empty())
            {
                ct++;
                dp[0][i][0] = ct;
            }

        for (int i = 1; i < logm; i++)
            for (int j = 0; j < n; j++)
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j + (1 << (i - 1))][0]);

        for (int i = 1; i < k; i++)
        {
            for (int j = 0; j < n; j++)
                if (nums[j].size() <= i)
                {
                    int bef = j;
                    for (int in = 0; in < nums[j].size(); in++)
                    {
                        while (in < nums[j].size() - 1)
                            if (nums[j][in] == nums[j][in + 1])
                                in++;
                        int maxlog = log2(bef - nums[j][in] + 1);
                        dp[0][j][i] = max(dp[0][j][i], 1 + max(dp[maxlog][nums[j][in]][i - in - 1], dp[maxlog][bef - maxlog + 1][i - in - 1]));
                        bef = nums[j][in] - 1;
                    }
                }
            for (int j = 1; j < logm; j++)
                for (int l = 0; l < n; l++)
                    dp[j][l][i] = max(dp[j - 1][l][i], dp[j - 1][l + (1 << (j - 1))][i]);
        }
        
    }
}