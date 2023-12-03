#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 100000;
int arr[maxn], parcent[maxn];
vector<int> adjlist[maxn];
bitset<maxn> used;

int siz[maxn];
int dfs1(int cur, int par)
{
    siz[cur] = 1;
    for (auto a : adjlist[cur])
        if (a != par && !used[a])
            siz[cur] += dfs1(a, cur);
    return siz[cur];
}

int numintree;

int dfs2(int cur, int par)
{
    for (auto a : adjlist[cur])
        if (a != par && !used[a])
            if (siz[a] * 2 > numintree)
                return dfs2(a, par);
    return cur;
}

int curcent;

vector<int> segtree[maxn], lazy[maxn];
void lazyv(int curin)
{
    segtree[curcent][curin] += lazy[curcent][curin];
    if (curin * 2 + 1 < lazy[curcent].size())
        lazy[curcent][curin * 2 + 1] += lazy[curcent][curin];
    if (curin * 2 + 2 < lazy[curcent].size())
        lazy[curcent][curin * 2 + 2] += lazy[curcent][curin];
    lazy[curcent][curin] = 0;
}

int ql, qr, val;
void update(int curin, int curl, int curr)
{
    lazyv(curin);
    if (qr < curl || curr > ql)
        return;
    if (ql <= curl && curr <= qr)
    {
        lazy[curcent][curin] = val;
        lazyv(curin);
        return;
    }
    update(curin * 2 + 1, curl, (curl + curr) / 2), update(curin * 2 + 2, (curl + curr) / 2 + 1, curr);
    segtree[curin] = max(segtree[curin * 2 + 1], segtree[curin * 2 + 2]);
}

int query(int curin, int curl, int curr)
{
    lazyv(curin);
    if (qr < curl || curr > ql)
        return 0;
    if (ql <= curl && curr <= qr)
        return segtree[curcent][curin];
    return max(query(curin * 2 + 1, curl, (curl + curr) / 2), query(curin * 2 + 2, (curl + curr) / 2 + 1, curr));
}

int timer;
map<int, int> starttime[maxn], endtime[maxn];
int eulertour(int cur, int par, int curval)
{
    siz[cur] = 1;
    ql = timer, qr = timer, val = curval;
    update(0, 0, numintree - 1);
    starttime[curcent][cur] = timer++;
    for (auto a : adjlist[cur])
        if (a != par && !used[a])
            siz[cur] += eulertour(a, cur, curval + arr[a]);
    endtime[curcent][cur] = timer;
    return siz[cur];
}

int lastans;
void eachcent(int cur, int siz, int oldcent)
{
    dfs1(cur, -1);

    numintree = siz;
    int cent = dfs2(cur, -1);

    parcent[cent] = oldcent;

    timer = 0;
    curcent = cent;
    segtree[cent].resize(4 * siz), lazy[cent].resize(4 * siz);
    eulertour(cur, -1, 0);

    int max1 = 0, max2 = 0;
    for (auto a : adjlist[cent])
        if (!used[a])
        {
            ql = starttime[cent][a], qr = endtime[cent][a] - 1;
            int res = query(0, 0, siz - 1);
            if (res >= max1)
            {
                swap(max1, max2);
                max1 = res;
            }
            else if (res > max2)
                max2 = res;
        }
    lastans = max(lastans, max1 + max2 + arr[cent]);

    used[cent] = 1;
    for (auto a : adjlist[cent])
        if (!used[a])
            eachcent(a, ::siz[a], cent);
}



signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    lastans = arr[0];
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adjlist[a - 1].push_back(b - 1), adjlist[b - 1].push_back(a - 1);
    }
    used.reset();
    eachcent(0, n, -1);
    cout<<lastans<<'\n';
    while(m--)
    {
        int in,val;
        cin>>in>>val;
        in--;
        int orig = in;
        while(in != -1)
        {
            //deciding
            in = parcent[in];
        }
    }
}