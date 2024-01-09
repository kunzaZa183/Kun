#include "colorblind.h"
#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, vector<int>> a, pair<int, vector<int>> b)
{
    return a.second.size() > b.second.size();
}
string investivate_colors(int N)
{
    if (N == 1)
        return "RB";
    vector<int> vi(2 * N);
    map<int, vector<int>> mii;
    for (int i = 1; i < 2 * N; i++)
    {
        vi[i] = use_device(0, i);
        mii[vi[i]].push_back(i);
    }
    vector<pair<int, vector<int>>> vpivi;
    for (auto x : mii)
        vpivi.emplace_back(x);
    sort(vpivi.begin(), vpivi.end(), cmp);

    pair<int, vector<int>> actual;
    if (vpivi.size() == 2)
        actual = vpivi.front();
    else if (vpivi.front().second.size() > vpivi[1].second.size())
        actual = vpivi.front();
    else if (vpivi.front().second.size() == vpivi[1].second.size())
    {
        string ans(2 * N, 'B');
        for (auto a : vpivi.front().second)
            ans[a] = 'R';
        ans[0] = 'R';
        vector<int> vi;
        int sum = 0;
        for (int i = 0; i < 2 * N; i++)
            if (vi.empty())
                vi.push_back(ans[i]);
            else if (ans[vi.back()] == ans[i])
                vi.push_back(ans[i]);
            else if (ans[vi.back()] != ans[i])
            {
                sum += i - vi.back();
                vi.pop_back();
            }

        for (auto &a : ans)
            if (a == 'B')
                a = 'R';
            else if (a == 'R')
                a = 'B';
        vi.clear();
        ans.clear();
        ans.resize(2 * N, 'B');
        for (auto a : vpivi[1].second)
            ans[a] = 'R';
        ans[0] = 'R';
        int sum2 = 0;
        for (int i = 0; i < 2 * N; i++)
            if (vi.empty())
                vi.push_back(ans[i]);
            else if (ans[vi.back()] == ans[i])
                vi.push_back(ans[i]);
            else if (ans[vi.back()] != ans[i])
            {
                sum2 += i - vi.back();
                vi.pop_back();
            }

        if (sum == sum2)
        {
            if (vpivi.front().first == sum)
                actual = vpivi.front();
            else
                actual = vpivi[1];
        }
        else if (sum == vpivi.front().first)
            actual = vpivi.front();
        else if (sum2 == vpivi[1].first)
            actual = vpivi[1];
    }

    string ans(2 * N, 'B');
    for (auto a : actual.second)
        ans[a] = 'R';
    ans[0] = 'R';
    if (actual.second.size() == N)
        ans[1] = 'B';
    return ans;
}