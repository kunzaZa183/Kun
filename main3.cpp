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
const int maxk = 10;
// int dp[maxk + 1][maxn + 1];//left, before number
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
                nums[l].push_back(i);
                l = find_ans(l + 1);
            }
        }

        int alwaysdry = 0;
        map<vector<int>, int> pairmap;
        map<int, int> mii;
        for (int i = 0; i < n; i++)
            if (nums[i].size() == 1)
                mii[nums[i][0]]++;
            else if (nums[i].size() == 2)
                pairmap[nums[i]]++;
            else if (nums[i].empty())
                alwaysdry++;
        vector<int> tmp;
        for (auto a : mii)
            tmp.push_back(a.second);
        sort(tmp.begin(), tmp.end(), greater<int>());
        int maxi = 0;
        if (tmp.size() >= 2)
            maxi = tmp[0] + tmp[1];
        else if (tmp.size() == 1)
            maxi = tmp[0];

        for (auto a : pairmap)
            maxi = max(maxi, a.second + mii[a.first[0]] + mii[a.first[1]]);
        cout << maxi + alwaysdry << "\n";
    }
}