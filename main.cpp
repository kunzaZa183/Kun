#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000, maxm = 200000, maxk = 10, logm = 20, verysmall = -1000000;
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
pair<int, int> alldays[maxm];
int dp[logm][maxn][maxk + 1]; // logthingy, last index, left
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
            sort(nums[i].begin(), nums[i].end(), greater<int>());

        for (int i = 0; i < logm; i++)
            for (int j = 0; j < n; j++)
                for (int k2 = 0; k2 <= k; k2++)
                    dp[i][j][k2] = verysmall;

        int ct = 0;
        for (int i = 0; i < n; i++)
            if (nums[i].empty())
            {
                ct++;
                dp[0][i][0] = ct;
            }

        for (int i = 1; i < logm; i++)
            for (int j = 0; j < n; j++)
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][max(0, j - (1 << (i - 1)))][0]);

        for (int i = 1; i <= k; i++)
        {
            if (i >= nums[0].size())
                dp[0][0][i] = 1;
            for (int k = 1; k < logm; k++)
                dp[k][0][i] = dp[k - 1][0][i];
            for (int j = 1; j < n; j++)
            {
                if (nums[j].size() <= i)
                {
                    dp[0][j][i] = 1;

                    int bef = j - 1;
                    for (int in = 0; in < nums[j].size(); in++)
                    {
                        while (in < nums[j].size() - 1)
                            if ((nums[j][in] == nums[j][in + 1]) || bef < nums[j][in])
                                in++;
                            else
                                break;
                        if (bef < nums[j][in])
                            break;
                        int maxlog = log2(bef - nums[j][in] + 1);
                        dp[0][j][i] = max(dp[0][j][i], 1 + max(dp[maxlog][nums[j][in] + (1 << maxlog) - 1][i - in], dp[maxlog][bef][i - in]));
                        bef = nums[j][in] - 1;
                    }
                    if (bef != -1)
                    {
                        int maxlog = log2(bef + 1);
                        dp[0][j][i] = max(dp[0][j][i], 1 + dp[logm - 1][bef][i - nums[j].size()]);
                    }
                }
                for (int k = 1; k < logm; k++)
                    dp[k][j][i] = max(dp[k - 1][j][i], dp[k - 1][max(0, j - (1 << (k - 1)))][i]);
            }
        }

        int maxi = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= k; j++)
                maxi = max(maxi, dp[logm - 1][i][j]);
        cout << maxi << "\n";
    }
}