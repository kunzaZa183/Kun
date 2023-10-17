#include "coin.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000, bignum = int(1e9);
int tape, n;
int rail[maxn];
void initialize(int N, vector<int> Rail, int L)
{
    tape = L;
    n = N;
    for (int i = 0; i < n; i++)
        rail[i] = Rail[i];
}
struct coin
{
    int start, size, bounce, id, segid;
};
bool sortstart(coin a, coin b)
{
    return a.start < b.start;
}
bool sortsize(coin a, coin b)
{
    return a.size < b.size;
}

coin allcoin[maxn], segcoin[maxn], startcoin[maxn];
int sizonly[maxn];

pair<int, int> minseg[4 * maxn]; // val id
int lazyminseg[4 * maxn] = {};
void buildmin(int curin, int curl, int curr)
{
    if (curl == curr)
    {
        minseg[curin] = {0, curl};
        return;
    }
    buildmin(curin * 2 + 1, curl, (curl + curr) / 2), buildmin(curin * 2 + 2, (curl + curr) / 2 + 1, curr);
    minseg[curin] = min(minseg[curin * 2 + 1], minseg[curin * 2 + 2]);
}
void lazymin(int curin)
{
    minseg[curin].first += lazyminseg[curin];
    if (curin * 2 + 1 < 4 * maxn)
        lazyminseg[curin * 2 + 1] += lazyminseg[curin];
    if (curin * 2 + 2 < 4 * maxn)
        lazyminseg[curin * 2 + 2] += lazyminseg[curin];
    lazyminseg[curin] = 0;
}
void updatemin(int curin, int curl, int curr, int ql, int qr, int val)
{
    lazymin(curin);
    if (qr < curl || ql > curr)
        return;
    if (ql <= curl && curr <= qr)
    {
        lazyminseg[curin] = val;
        lazymin(curin);
        return;
    }
    updatemin(curin * 2 + 1, curl, (curl + curr) / 2, ql, qr, val), updatemin(curin * 2 + 2, (curl + curr) / 2 + 1, curr, ql, qr, val);
    minseg[curin] = min(minseg[curin * 2 + 1], minseg[curin * 2 + 2]);
}
pair<int, int> querymin(int curin, int curl, int curr, int ql, int qr)
{
    lazymin(curin);
    if (qr < curl || ql > curr)
        return {INT_MAX, INT_MAX};
    if (ql <= curl && curr <= qr)
        return minseg[curin];
    return min(querymin(curin * 2 + 1, curl, (curl + curr) / 2, ql, qr), querymin(curin * 2 + 2, (curl + curr) / 2 + 1, curr, ql, qr));
}

pair<int, int> biggestarr[maxn] = {}; // cur biggest
int lazybiggestseg[4 * maxn] = {};
void lazybiggest(int curin, int curl, int curr)
{
    if (curl == curr)
    {
        biggestarr[curl].first += lazybiggestseg[curin];
        biggestarr[curl].second = max(biggestarr[curl].second, biggestarr[curl].first);
        return;
    }
    lazybiggestseg[curin * 2 + 1] += lazybiggestseg[curin], lazybiggestseg[curin * 2 + 2] += lazybiggestseg[curin];
}
void updatebig(int curin, int curl, int curr, int ql, int qr, int val)
{
    lazybiggest(curin, curl, curr);
    if (qr < curl || ql > curr)
        return;
    if (ql <= curl && curr <= qr)
    {
        lazybiggestseg[curin] = val;
        lazybiggest(curin, curl, curr);
        return;
    }
    updatebig(curin * 2 + 1, curl, (curl + curr) / 2, ql, qr, val), updatebig(curin * 2 + 2, (curl + curr) / 2 + 1, curr, ql, qr, val);
}
void querybig(int curin, int curl, int curr, int in)
{
    lazybiggest(curin, curl, curr);
    if (in < curl || in > curr)
        return;
    if (curl == curr)
        return;
    querybig(curin * 2 + 1, curl, (curl + curr) / 2, in), querybig(curin * 2 + 2, (curl + curr) / 2 + 1, curr, in);
}

vector<int> max_dist(vector<vector<int>> Coins)
{
    for (int i = 0; i < Coins.size(); i++)
    {
        allcoin[i] = {Coins[i][0], Coins[i][2], Coins[i][1], i, -1};
        segcoin[i] = allcoin[i];
    }
    sort(segcoin, segcoin + Coins.size(), sortsize);
    for (int i = 0; i < Coins.size(); i++)
    {
        segcoin[i].segid = i;
        allcoin[segcoin[i].id].segid = i;
    }
    for (int i = 0; i < Coins.size(); i++)
        startcoin[i] = allcoin[i];
    sort(startcoin, startcoin + Coins.size(), sortstart);
    buildmin(0, 0, n - 1);
    updatemin(0, 0, n - 1, 0, n - 1, bignum);
    int curin = 0;
    for (int i = 0; i < n; i++)
    {
        while (allcoin[curin].start == i)
        {
            pair<int, int> tmp = querymin(0, 0, n - 1, allcoin[curin].segid, allcoin[curin].segid);
            updatemin(0, 0, n - 1, allcoin[curin].segid, allcoin[curin].segid, -tmp.first);
            biggestarr[allcoin[curin].segid] = {0, 0};
            curin++;
        }
        if (i == 0)
        {
            for (int j = 0; j < tape; j++)
            {
                
            }
        }
    }
}
