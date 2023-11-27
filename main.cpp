#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 200000;
vector<int> adjlist[maxn], sccadjlist[maxn];
set<int> tmpvsi[maxn];
int arr[maxn], disc[maxn], link[maxn], whichscc[maxn], scclongest[maxn], sccminval[maxn];
bitset<maxn> bsi;
vector<int> si;
int curtime = 0;
vector<vector<int>> sccs;
void dfs(int cur)
{
    disc[cur] = curtime++;
    link[cur] = disc[cur];
    si.push_back(cur);
    bsi[cur] = 1;
    for (auto a : adjlist[cur])
        if (disc[a] == -1)
        {
            dfs(a);
            link[cur] = min(link[cur], link[a]);
        }
        else if (bsi[a])
            link[cur] = min(link[cur], link[a]);
    if (link[cur] == disc[cur])
    {
        sccs.push_back(vector<int>());
        while (!si.empty())
        {
            int tmp = si.back();
            si.pop_back();
            bsi[tmp] = 0;
            whichscc[tmp] = sccs.size() - 1;
            sccs.back().push_back(tmp);
            if (sccs.back().back() == cur)
                break;
        }
    }
}
pair<int, int> sccdfs(int cur)
{
    if (scclongest[cur] == -1)
    {
        scclongest[cur] = sccs[cur].size();
        sccminval[cur] = 0;
        for (auto a : sccs[cur])
            sccminval[cur] += arr[a];
        pair<int, int> optimal(0, 0);
        for (auto a : sccadjlist[cur])
        {
            pair<int, int> tmp = sccdfs(a);
            if ((tmp.first > optimal.first) || (tmp.first == optimal.first && tmp.second < optimal.second))
                optimal.swap(tmp);
        }
        scclongest[cur] += optimal.first;
        sccminval[cur] += optimal.second;
    }
    return {scclongest[cur], sccminval[cur]};
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            adjlist[i].clear(), tmpvsi[i].clear();
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            a--, b--;
            if (a != b)
                tmpvsi[a].insert(b);
        }
        for (int i = 0; i < n; i++)
            for (auto a : tmpvsi[i])
                adjlist[i].push_back(a);
        memset(disc, -1, sizeof disc);
        si.clear();
        bsi.reset();
        sccs.clear();
        for (int i = 0; i < n; i++)
            if (disc[i] == -1)
                dfs(i);
        for (int i = 0; i < n; i++)
            tmpvsi[i].clear(), sccadjlist[i].clear();
        for (int i = 0; i < n; i++)
            for (auto a : adjlist[i])
                tmpvsi[whichscc[i]].insert(whichscc[a]);
        for (int i = 0; i < n; i++)
            for (auto a : tmpvsi[i])
                if (i != a)
                    sccadjlist[i].push_back(a);
        memset(scclongest, -1, sizeof scclongest), memset(sccminval, -1, sizeof sccminval);
        pair<int, int> ans(0, 0);
        for (int i = 0; i < sccs.size(); i++)
        {
            pair<int, int> tmp = sccdfs(i);
            if ((tmp.first > ans.first) || (tmp.first == ans.first && tmp.second < ans.second))
                ans.swap(tmp);
        }
        cout << ans.first << " " << ans.second << "\n";
    }
}