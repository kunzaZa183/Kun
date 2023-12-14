#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000, logn = 17;
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

int dfs2(int cur, int par, int idealnum)
{
    for (auto a : adjlist[cur])
        if (a != par && !used[a])
            if (siz[a] * 2 > idealnum)
                return dfs2(a, cur, idealnum);
    return cur;
}

int ql, qr, val;

struct lazyseg
{
    int seg[2 * maxn], lazy[2 * maxn];
    void push(int curin, int curl, int curr)
    {
        if (curl != curr)
            lazy[curin * 2 + 1] += lazy[curin], lazy[curin * 2 + 2] += lazy[curin];
        seg[curin] += lazy[curin];
        lazy[curin] = 0;
    }

    void update(int curin, int curl, int curr)
    {
        push(curin, curl, curr);

        if (qr < curl || curr < ql)
            return;
        if (ql <= curl && curr <= qr)
        {
            lazy[curin] = val;
            push(curin, curl, curr);
            return;
        }
        update(curin * 2 + 1, curl, (curl + curr) / 2), update(curin * 2 + 2, (curl + curr) / 2 + 1, curr);
        seg[curin] = max(seg[curin * 2 + 1], seg[curin * 2 + 2]);
    }

    int query(int curin, int curl, int curr)
    {
        push(curin, curl, curr);
        if (qr < curl || curr < ql)
            return 0;
        if (ql <= curl && curr <= qr)
            return seg[curin];
        return max(query(curin * 2 + 1, curl, (curl + curr) / 2), query(curin * 2 + 2, (curl + curr) / 2 + 1, curr));
    }

} segtree[logn];

int arrtimer[logn];
int starttime[logn][maxn], endtime[logn][maxn];
int eulertour(int cur, int level, int par, int curval)
{
    siz[cur] = 1;
    ql = arrtimer[level], qr = arrtimer[level], val = curval;
    segtree[level].update(0, 0, maxn - 1);
    starttime[level][cur] = arrtimer[level]++;
    for (auto a : adjlist[cur])
        if (a != par && !used[a])
            siz[cur] += eulertour(a, level, cur, curval + arr[a]);
    endtime[level][cur] = arrtimer[level];
    return siz[cur];
}

int parnextroot[logn][maxn];

void dfs3(int cur, int par, int nextroot, int level)
{
    parnextroot[level][cur] = nextroot;
    for (auto a : adjlist[cur])
        if (!used[a] && a != par)
            dfs3(a, cur, nextroot, level);
}

struct multi
{
    priority_queue<int> pq1, pq2;
    void add(int x)
    {
        pq1.push(x);
    }
    void del(int x)
    {
        pq2.push(x);
    }
    pair<int, int> get2max()
    {
        while (!pq2.empty())
            if (pq1.top() == pq2.top())
                pq1.pop(), pq2.pop();
            else
                break;
        pair<int, int> ret;
        ret.first = pq1.top();
        pq1.pop();
        while (!pq2.empty())
            if (pq1.top() == pq2.top())
                pq1.pop(), pq2.pop();
            else
                break;
        ret.second = pq1.top();
        pq1.push(ret.first);
        return ret;
    }
};

multi allans, alldowncent[maxn];
int oldans[maxn];

int centlevel[maxn];

int sum(pair<int, int> a)
{
    return a.first + a.second;
}

void eachcent(int cur, int siz, int oldcent, int level)
{
    dfs1(cur, -1);
    int cent = dfs2(cur, -1, siz);
    parcent[cent] = oldcent;
    centlevel[cent] = level;

    eulertour(cent, level, -1, 0);
    alldowncent[cent].add(0);
    for (auto a : adjlist[cent])
    {
        ql = starttime[level][a], qr = endtime[level][a] - 1;
        alldowncent[cent].add(segtree[level].query(0, 0, maxn - 1));
        dfs3(a, cent, a, level);
    }
    oldans[cent] = sum(alldowncent[cent].get2max()) + arr[cent];
    allans.add(oldans[cent]);

    used[cent] = 1;
    for (auto a : adjlist[cent])
        if (!used[a])
            eachcent(a, ::siz[a], cent, level + 1);
}

int main()
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
    eachcent(0, n, -1, 0);
    cout << allans.get2max().first << '\n';
    while (m--)
    {
        int in, val;
        cin >> in >> val;
        in--;
        int change = val - arr[in];
        arr[in] = val;
        int curlev = centlevel[in];
        allans.del(oldans[in]);

        oldans[in] = sum(alldowncent[in].get2max()) + arr[in];
        allans.add(oldans[in]);
        int orig = in;
        in = parcent[in];
        curlev--;
        while (curlev >= 0)
        {
            allans.del(oldans[in]);
            int nextroot = parnextroot[curlev][orig];
            ql = starttime[curlev][nextroot], qr = endtime[curlev][nextroot] - 1;
            alldowncent[in].del(segtree[curlev].query(0, 0, maxn - 1));
            ql = starttime[curlev][orig], qr = endtime[curlev][orig] - 1, ::val = change;
            segtree[curlev].update(0, 0, maxn - 1);
            ql = starttime[curlev][nextroot], qr = endtime[curlev][nextroot] - 1;
            alldowncent[in].add(segtree[curlev].query(0, 0, maxn - 1));
            oldans[in] = sum(alldowncent[in].get2max()) + arr[in];
            allans.add(oldans[in]);
            in = parcent[in];
            curlev--;
        }
        cout << allans.get2max().first << '\n';
    }
}