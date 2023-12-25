#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<string> vs;
    string s;
    while (cin >> s, s != "Q")
        vs.push_back(s);
    vector<bool> row(vs.size()), column(vs.front().size());
    for (int i = 0; i < vs.size(); i++)
        if (find(vs[i].begin(), vs[i].end(), '#') == vs[i].end())
            row[i] = 1;
    for (int j = 0; j < vs[0].size(); j++)
    {
        for (int i = 0; i < vs.size(); i++)
            if (vs[i][j] == '#')
                goto A;
        column[j] = 1;
    A:;
    }
    vector<pair<int, int>> vpii;
    for (int i = 0; i < vs.size(); i++)
        for (int j = 0; j < vs[0].size(); j++)
            if (vs[i][j] == '#')
                vpii.emplace_back(i, j);
    int sum = 0;
    for (int i = 0; i < vpii.size(); i++)
        for (int j = i + 1; j < vpii.size(); j++)
        {
            pair<int, int> x1 = {vpii[i].first, vpii[j].first}, y1 = {vpii[i].second, vpii[j].second};
            if (x1.first > x1.second)
                swap(x1.first, x1.second);
            if (y1.first > y1.second)
                swap(y1.first, y1.second);
            for (int k = x1.first; k < x1.second; k++)
                if (row[k])
                    sum += 999999;
            for (int k = y1.first; k < y1.second; k++)
                if (column[k])
                    sum += 999999;
            sum += (x1.second - x1.first) + (y1.second - y1.first);
        }
    cout << sum << '\n';
}