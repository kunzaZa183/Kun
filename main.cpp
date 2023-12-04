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
                return dfs2(a, cur);
    return cur;
}

int curcent;

vector<pair<int, int>> segtree[maxn];
vector<int> lazy[maxn];
void lazyv(int curin)
{
    segtree[curcent][curin].first += lazy[curcent][curin], segtree[curcent][curin].second += lazy[curcent][curin];
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

    if (qr < curl || curr < ql)
        return;
    if (ql <= curl && curr <= qr)
    {
        if (curl == curr)
        {
            segtree[curcent][curin].first += val;
            segtree[curcent][curin].second = LLONG_MIN;
            return;
        }
        lazy[curcent][curin] = val;
        lazyv(curin);
        return;
    }
    update(curin * 2 + 1, curl, (curl + curr) / 2), update(curin * 2 + 2, (curl + curr) / 2 + 1, curr);

    pair<int, int> pii1 = segtree[curcent][curin * 2 + 1], pii2 = segtree[curcent][curin * 2 + 2];
    int arr[4] = { pii1.first, pii1.second, pii2.first, pii2.second };
    sort(arr, arr + 4);
    segtree[curcent][curin] = { arr[2], arr[3] };
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

multiset<int> allans;
int oldans[maxn];

void eachcent(int cur, int siz, int oldcent)
{
    if (siz == 1)
    {
        parcent[cur] = oldcent;
        oldans[cur] = arr[cur];
        allans.insert(arr[cur]);
        used[cur] = 1;
        return;
    }
    dfs1(cur, -1);

    numintree = siz;
    int cent = dfs2(cur, -1);

    parcent[cent] = oldcent;

    timer = 0;
    curcent = cent;
    segtree[cent].resize(4 * siz), lazy[cent].resize(4 * siz);
    eulertour(cent, -1, 0);

    int ql = 0, qr = siz - 1;
    oldans[cent] = segtree[cent][0].first + segtree[cent][0].second + arr[cent];
    allans.insert(oldans[cent]);

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
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adjlist[a - 1].push_back(b - 1), adjlist[b - 1].push_back(a - 1);
    }
    used.reset();
    eachcent(0, n, -1);
    cout << *allans.rbegin() << '\n';
    while (m--)
    {
        int in, val;
        cin >> in >> val;
        in--;
        int change = val - arr[in];
        arr[in] = val;

        if (segtree[in].empty())
        {
            allans.erase(allans.find(oldans[in]));
            oldans[in] = val;
            allans.insert(val);
        }
        else
        {
            allans.erase(allans.find(oldans[in]));
            oldans[in] = segtree[in][0].first + segtree[in][0].second + arr[in];
            allans.insert(oldans[in]);
        }
        int orig = in;
        in = parcent[in];
        while (in != -1)
        {
            allans.erase(allans.find(oldans[in]));
            curcent = in, ql = starttime[in][orig], qr = endtime[in][orig] - 1, ::val = change;
            update(0, 0, segtree[curcent].size() / 4 - 1);
            oldans[in] = segtree[in][0].first + segtree[in][0].second + arr[in];
            allans.insert(oldans[in]);
            in = parcent[in];
        }
        cout << *allans.rbegin() << '\n';
    }
}