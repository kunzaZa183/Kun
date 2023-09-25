#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 200000;
int arr[maxn], ans[maxn];
int streesiz[maxn], parent[maxn];
vector<int> adjlist[maxn];
int dfs(int cur, int par)
{
    streesiz[cur] = 1;
    parent[cur] = par;
    for (auto a : adjlist[cur])
        if (a != par)
            streesiz[cur] += dfs(a, cur);
    return streesiz[cur];
}
const int root = 0;
int curbit;
void dfs2(int cur, int changed)
{
    int tmp;
    if (arr[cur] & (1 << curbit))
        tmp = 1;
    else
        tmp = 0;
    if (changed)
        tmp = 1 - tmp;
    int tmp2;
    if (arr[root] & (1 << curbit))
        tmp2 = 1;
    else
        tmp2 = 0;
    if (tmp == tmp2)
    {
        for (auto a : adjlist[cur])
            if (parent[cur] != a)
                dfs2(a, changed);
    }
    else
    {
        ans[root] += streesiz[cur] * (1 << curbit);
        for (auto a : adjlist[cur])
            if (parent[cur] != a)
                dfs2(a, 1 - changed);
    }
}
const int bits = 20;
int n;
void dfs3(int cur)
{
    for (auto a : adjlist[cur])
        if (parent[cur] != a)
        {
            ans[a] = ans[cur];
            for (int i = 0; i < bits; i++)
                if ((arr[cur] & (1 << i)) != (arr[a] & (1 << i)))
                {
                    ans[a] -= streesiz[a] * (1 << i);
                    ans[a] += (n - streesiz[a]) * (1 << i);
                }
            dfs3(a);
        }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = 0; i < n; i++)
            streesiz[i] = 0, adjlist[i].clear(), parent[i] = 0, ans[i] = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int a, b;
            cin >> a >> b;
            a--, b--;
            adjlist[a].push_back(b), adjlist[b].push_back(a);
        }
        dfs(root, root);
        for (curbit = 0; curbit < bits; curbit++)
            dfs2(root, 0);
        dfs3(root);
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
}