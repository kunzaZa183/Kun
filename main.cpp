#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000, color = 5, BIGNUM = 1e9, endtime = 1e8 + 1;
struct hole
{
    int place, time, l, r;
    friend bool operator<(hole &a, hole &b)
    {
        return a.place < b.place;
    }
};
struct slow
{
    int time, l, r, speed; // more becomes less
    friend bool operator<(slow &a, slow &b)
    {
        return a.time < b.time;
    }
};
int arr[maxn], ans[maxn];
pair<int, int> segtree[color + 1][4 * maxn];
vector<hole> vh;
vector<slow> vs;
map<int, int> spii[color + 1];
void build(int col, int curin, int curl, int curr)
{
    if (curl == curr)
    {
        segtree[col][curin] = {BIGNUM, curl};
        return;
    }
    build(col, curin * 2 + 1, curl, (curl + curr) / 2), build(col, curin * 2 + 2, (curl + curr) / 2 + 1, curr);
    segtree[col][curin] = min(segtree[col][curin * 2 + 1], segtree[col][curin * 2 + 2]);
}
void update(int col, int curin, int curl, int curr, int in, int val)
{
    if (in < curl || in > curr)
        return;
    if (curl == curr)
    {
        segtree[col][curin] = {val, in};
        return;
    }
    int mid = (curl + curr) / 2;
    if (in <= mid)
        update(col, curin * 2 + 1, curl, mid, in, val);
    else if (in > mid)
        update(col, curin * 2 + 2, mid + 1, curr, in, val);
    segtree[col][curin] = min(segtree[col][curin * 2 + 1], segtree[col][curin * 2 + 2]);
}
pair<int, int> minq(int col, int curin, int curl, int curr, int ql, int qr)
{
    if (ql > curr || qr < curl)
        return {BIGNUM, -1};
    if (ql <= curl && curr <= qr)
        return segtree[col][curin];
    int mid = (curl + curr) / 2;
    return min(minq(col, curin * 2 + 1, curl, mid, ql, qr), minq(col, curin * 2 + 2, mid + 1, curr, ql, qr));
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < color; i++)
        build(i, 0, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        update(arr[i], 0, 0, n - 1, i, 0);
        spii[arr[i]][i] = 0;
    }

    while (m--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            hole tmp;
            cin >> tmp.time >> tmp.l >> tmp.r >> tmp.place;
            vh.push_back(tmp);
        }
        else if (type == 2)
        {
            slow tmp;
            cin >> tmp.time >> tmp.l >> tmp.r >> tmp.speed;
            vs.push_back(tmp);
        }
    }

    sort(vh.begin(), vh.end());
    sort(vs.begin(), vs.end());

    for (auto &a : vs)
        for (int j = a.speed + 1; j <= color; j++)
        {
            auto it = spii[j].lower_bound(a.l);
            while (it != spii[j].end())
            {
                if (it->first > a.r)
                    break;
                update(a.speed, 0, 0, n - 1, it->first, (a.time - 1) * j + it->second - a.speed * (a.time - 1));
                spii[a.speed][it->first] = (a.time - 1) * j + it->second - a.speed * (a.time - 1);
                it = spii[j].erase(it);
            }
        }

    for (int i = 0; i < n; i++)
        for (int j = 1; j <= color; j++)
        {
            pair<int, int> x = minq(j, 0, 0, n - 1, i, i);
            if (x.first != BIGNUM)
            {
                ans[i] = (endtime - 1) * j + x.first;
                break;
            }
        }

    for (auto &a : vh)
    {
        for (int j = 1; j <= color; j++)
        {
            pair<int, int> x = minq(j, 0, 0, n - 1, a.l, a.r);
            while (x.first + (a.time - 1) * j <= a.place)
            {
                ans[x.second] = min(ans[x.second], a.place);
                for (int k = 1; k <= color; k++)
                    update(k, 0, 0, n - 1, x.second, BIGNUM);
                x = minq(j, 0, 0, n - 1, a.l, a.r);
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << "\n";
}