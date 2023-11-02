//CF while back
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000;
pair<int, int> allsegments[maxn];
struct event
{
    int point;
    bool start;
    int id;
    event(int a, int b, int c)
    {
        point = a, start = b, id = c;
    }
    friend bool operator<(const event& a, const event& b)
    {
        return a.point < b.point;
    }
};
vector<event> allpoints;
int segtree[8 * maxn], lazy[8 * maxn];
void lazyv(int curin)
{
    segtree[curin] += lazy[curin];
    if (curin * 2 + 1 < 4 * maxn)
        lazy[curin * 2 + 1] += lazy[curin];
    if (curin * 2 + 2 < 4 * maxn)
        lazy[curin * 2 + 2] += lazy[curin];
    lazy[curin] = 0;
}
void update(int curin, int curl, int curr, int ql, int qr, int val)
{
    lazyv(curin);
    if (ql > curr || qr < curl)
        return;
    if (ql <= curl && curr <= qr)
    {
        lazy[curin] = val;
        lazyv(curin);
        return;
    }
    update(curin * 2 + 1, curl, (curl + curr) / 2, ql, qr, val), update(curin * 2 + 2, (curl + curr) / 2 + 1, curr, ql, qr, val);
    segtree[curin] = max(segtree[curin * 2 + 1], segtree[curin * 2 + 2]);
}
int lowerb(int num, vector<int>& vi)
{
    return lower_bound(vi.begin(), vi.end(), num) - vi.begin();
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--)
    {
        memset(segtree, 0, sizeof segtree);
        memset(lazy, 0, sizeof lazy);
        int n, m;
        cin >> n >> m;
        set<int> si;
        si.insert(0);
        for (int i = 0; i < n; i++)
        {
            cin >> allsegments[i].first >> allsegments[i].second;
            allsegments[i].first--, allsegments[i].second--;
            si.insert(allsegments[i].first), si.insert(allsegments[i].second + 1);
        }
        allpoints.clear();
        for (int i = 0; i < n; i++)
            allpoints.emplace_back(allsegments[i].first, 1, i), allpoints.emplace_back(allsegments[i].second + 1, 0, i);
        sort(allpoints.begin(), allpoints.end());
        vector<int> usethis;
        for (auto a : si)
            usethis.push_back(a);
        for (int i = 0; i < n; i++)
            update(0, 0, usethis.size() - 1, lowerb(allsegments[i].first, usethis), lowerb(allsegments[i].second + 1, usethis) - 1, 1);
        int curin = 0;
        int maxi = 0;
        for (auto a : usethis)
        {
            while (curin < allpoints.size())
            {
                if (allpoints[curin].point == a)
                {
                    if (allpoints[curin].start)
                        update(0, 0, usethis.size() - 1, lowerb(allsegments[allpoints[curin].id].first, usethis), lowerb(allsegments[allpoints[curin].id].second + 1, usethis) - 1, -1);
                    else
                        update(0, 0, usethis.size() - 1, lowerb(allsegments[allpoints[curin].id].first, usethis), lowerb(allsegments[allpoints[curin].id].second + 1, usethis) - 1, 1);
                    curin++;
                }
                else
                    break;
            }
            if (a < m)
                maxi = max(maxi, segtree[0]);
        }
        cout << maxi << '\n';
    }
}