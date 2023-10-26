#include <bits/stdc++.h>
using namespace std;
const int maxn = 1500, maxm = 1500;
int arr[maxn][maxm], topleft[maxn][maxm], topright[maxn][maxm], belowleft[maxn][maxm], belowright[maxn][maxm];
vector<pair<int, int>> spii;
int used[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int r, c;
    cin >> r >> c;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> arr[i][j];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            topleft[i][j] = arr[i][j], topright[i][j] = arr[i][j], belowleft[i][j] = arr[i][j], belowright[i][j] = arr[i][j];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            int ans = topleft[i][j];
            int mini = INT_MAX;
            if (i != 0)
                mini = min(mini, topleft[i - 1][j]);
            if (j != 0)
                mini = min(mini, topleft[i][j - 1]);
            if (mini != INT_MAX)
                topleft[i][j] = mini + ans;
        }
    for (int i = 0; i < r; i++)
        for (int j = c - 1; j >= 0; j--)
        {
            int ans = topright[i][j];
            int mini = INT_MAX;
            if (i != 0)
                mini = min(mini, topright[i - 1][j]);
            if (j != c - 1)
                mini = min(mini, topright[i][j + 1]);
            if (mini != INT_MAX)
                topright[i][j] = mini + ans;
        }
    for (int i = r - 1; i >= 0; i--)
        for (int j = 0; j < c; j++)
        {
            int ans = belowleft[i][j];
            int mini = INT_MAX;
            if (i != r - 1)
                mini = min(mini, belowleft[i + 1][j]);
            if (j != 0)
                mini = min(mini, belowleft[i][j - 1]);
            if (mini != INT_MAX)
                belowleft[i][j] = mini + ans;
        }
    for (int i = r - 1; i >= 0; i--)
        for (int j = c - 1; j >= 0; j--)
        {
            int ans = belowright[i][j];
            int mini = INT_MAX;
            if (i != r - 1)
                mini = min(mini, belowright[i + 1][j]);
            if (j != c - 1)
                mini = min(mini, belowright[i][j + 1]);
            if (mini != INT_MAX)
                belowright[i][j] = mini + ans;
        }
    int maxi = belowright[0][0] + topright[r - 1][0];
    // horizontal
    for (int i = 0; i < r; i++)
    {
        memset(used, 0, sizeof used);
        int sum = 0;
        spii.clear();
        for (int j = 0; j < c; j++)
        {
            spii.emplace_back(sum + topright[i][j] + belowright[i][j] - arr[i][j], j);
            sum += arr[i][j];
        }
        sort(spii.begin(), spii.end());
        int curin = 0;
        sum = 0;
        for (int j = 0; j < c; j++)
        {
            while (used[spii[curin].second])
                curin++;
            maxi = min(maxi, topleft[i][j] + belowleft[i][j] - arr[i][j] + spii[curin].first - sum - arr[i][j]);
            used[j] = 1;
            sum += arr[i][j];
        }
    }
    // vertical
    for (int j = 0; j < c; j++)
    {
        memset(used, 0, sizeof used);
        int sum = 0;
        spii.clear();
        for (int i = 0; i < r; i++)
        {
            spii.emplace_back(sum + belowleft[i][j] + belowright[i][j] - arr[i][j], i);
            sum += arr[i][j];
        }
        sort(spii.begin(), spii.end());
        int curin = 0;
        sum = 0;
        for (int i = 0; i < r; i++)
        {
            while (used[spii[curin].second])
                curin++;
            maxi = min(maxi, topleft[i][j] + topright[i][j] - arr[i][j] + spii[curin].first - sum - arr[i][j]);
            used[i] = 1;
            sum += arr[i][j];
        }
    }
    cout << maxi << '\n';
}