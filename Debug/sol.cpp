#include <bits/stdc++.h>
using namespace std;

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

vector<int> segtree[maxn], lazy[maxn];
inline void lazyv(int curin)
{
    segtree[curcent][curin] += lazy[curcent][curin];
    if (curin * 2 + 1 < lazy[curcent].size())
        lazy[curcent][curin * 2 + 1] += lazy[curcent][curin];
    if (curin * 2 + 2 < lazy[curcent].size())
        lazy[curcent][curin * 2 + 2] += lazy[curcent][curin];
    lazy[curcent][curin] = 0;
}

int ql, qr, val;
inline void update(int curin, int curl, int curr)
{
    lazyv(curin);

    if (qr < curl || curr < ql)
        return;
    if (ql <= curl && curr <= qr)
    {
        lazy[curcent][curin] = val;
        lazyv(curin);
        return;
    }
    update(curin * 2 + 1, curl, (curl + curr) / 2), update(curin * 2 + 2, (curl + curr) / 2 + 1, curr);
    segtree[curcent][curin] = max(segtree[curcent][curin * 2 + 1], segtree[curcent][curin * 2 + 2]);
}

inline int query(int curin, int curl, int curr)
{
    lazyv(curin);

    if (qr < curl || curr < ql)
        return 0;
    if (ql <= curl && curr <= qr)
        return segtree[curcent][curin];
    return max(query(curin * 2 + 1, curl, (curl + curr) / 2), query(curin * 2 + 2, (curl + curr) / 2 + 1, curr));
}

int timer;
map<int, int> starttime[maxn], endtime[maxn];
inline int eulertour(int cur, int par, int curval)
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

map<int, int> parnextroot[maxn];

int curnextroot;
inline void dfs3(int cur, int par)
{
    parnextroot[curcent][cur] = curnextroot;
    for (auto a : adjlist[cur])
        if (!used[a] && a != par)
            dfs3(a, cur);
}

multiset<int> allans, alldowncent[maxn];
int oldans[maxn];

inline int sumfirsttwo(multiset<int> &msi)
{
    auto it = msi.rbegin(), it2 = msi.rbegin();
    it2++;
    return *it + *it2;
}

inline void eachcent(int cur, int siz, int oldcent)
{
    {
        dfs1(cur, -1);
    }
    numintree = siz;
    int cent;
    {
        cent = dfs2(cur, -1);
    }
    parcent[cent] = oldcent;

    timer = 0;
    curcent = cent;
    segtree[cent].resize(4 * siz), lazy[cent].resize(4 * siz);
    {
        eulertour(cent, -1, 0);
    }
    alldowncent[cent].insert(0), alldowncent[cent].insert(0);
    for (auto a : adjlist[cent])
    {
        ql = starttime[cent][a], qr = endtime[cent][a] - 1;
        alldowncent[cent].insert(query(0, 0, siz - 1));
        curnextroot = a;
        {
            dfs3(a, cent);
        }
    }
    oldans[cent] = sumfirsttwo(alldowncent[cent]) + arr[cent];
    allans.insert(oldans[cent]);

    used[cent] = 1;
    for (auto a : adjlist[cent])
        if (!used[a])
            eachcent(a, ::siz[a], cent);
}
static void run_with_stack_size(void (*func)(void), size_t stsize)
{
    char *stack, *send;
    stack = (char *)malloc(stsize);
    send = stack + stsize - 16;
    send = (char *)((uintptr_t)send / 16 * 16);
    asm volatile(
        "mov %%rsp, (%0)\n"
        "mov %0, %%rsp\n"
        :
        : "r"(send));
    func();
    asm volatile("mov (%0), %%rsp\n" : : "r"(send));
    free(stack);
}

void main_()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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

        allans.erase(allans.find(oldans[in]));
        oldans[in] = sumfirsttwo(alldowncent[in]) + arr[in];
        allans.insert(oldans[in]);
        int orig = in;
        in = parcent[in];
        while (in != -1)
        {
            allans.erase(allans.find(oldans[in]));
            curcent = in;
            int nextroot = parnextroot[in][orig];

            ql = starttime[in][nextroot], qr = endtime[in][nextroot] - 1;
            int ql2 = ql, qr2 = qr;
            int debug = query(0, 0, segtree[curcent].size() / 4 - 1);
            if (alldowncent[in].find(debug) != alldowncent[in].end())
                alldowncent[in].erase(alldowncent[in].find(debug));

            ql = starttime[in][orig], qr = endtime[in][orig] - 1, ::val = change;
            update(0, 0, segtree[curcent].size() / 4 - 1);

            ql = ql2, qr = qr2;
            alldowncent[in].insert(query(0, 0, segtree[curcent].size() / 4 - 1));
            oldans[in] = sumfirsttwo(alldowncent[in]) + arr[in];
            allans.insert(oldans[in]);
            in = parcent[in];
        }
        cout << *allans.rbegin() << '\n';
    }
}

int main()
{
    run_with_stack_size(main_, 1024 * 1024 * 128);
    return 0;
}