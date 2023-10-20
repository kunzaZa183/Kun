#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000, maxq = 200000, bignum = int(1e9);
int tape, n, numcoin;
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

coin allcoin[maxq], segcoin[maxq], startcoin[maxq];
int sizonly[maxq];

int lesslower(int num)
{
    return lower_bound(sizonly, sizonly + numcoin, num) - sizonly - 1;
}

pair<int, int> minseg[4 * maxq]; // val id
int lazyminseg[4 * maxq] = {};
void buildmin(int curin, int curl, int curr)
{
    if (curl == curr)
    {
        minseg[curin] = {0, curl};
        return;
    }
    buildmin(curin << 1 | 1, curl, (curl + curr) >> 1), buildmin((curin << 1) + 2, ((curl + curr) >> 1) + 1, curr);
    minseg[curin] = min(minseg[curin << 1 | 1], minseg[(curin << 1) + 2]);
}
void lazymin(int curin)
{
    minseg[curin].first += lazyminseg[curin];
    if ((curin << 1 | 1) < 4 * maxq)
        lazyminseg[curin << 1 | 1] += lazyminseg[curin];
    if (((curin << 1) + 2) < 4 * maxq)
        lazyminseg[(curin << 1) + 2] += lazyminseg[curin];
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
    updatemin(curin << 1 | 1, curl, (curl + curr) >> 1, ql, qr, val), updatemin((curin << 1) + 2, ((curl + curr) >> 1) + 1, curr, ql, qr, val);
    minseg[curin] = min(minseg[curin << 1 | 1], minseg[(curin << 1) + 2]);
}
pair<int, int> querymin(int curin, int curl, int curr, int ql, int qr)
{
    lazymin(curin);
    if (qr < curl || ql > curr)
        return {INT_MAX, INT_MAX};
    if (ql <= curl && curr <= qr)
        return minseg[curin];
    return min(querymin(curin << 1 | 1, curl, (curl + curr) >> 1, ql, qr), querymin((curin << 1) + 2, ((curl + curr) >> 1) + 1, curr, ql, qr));
}

pair<int, int> biggestarr[maxq] = {}; // cur biggest
pair<int, int> lazybiggestseg[4 * maxq] = {};
void lazybiggest(int curin, int curl, int curr)
{
    if (curl == curr)
    {
        biggestarr[curl].second = max(biggestarr[curl].second, biggestarr[curl].first + lazybiggestseg[curin].second);
        biggestarr[curl].first += lazybiggestseg[curin].first;
        lazybiggestseg[curin] = {0, 0};
        return;
    }
    lazybiggestseg[curin << 1 | 1].second = max(lazybiggestseg[curin << 1 | 1].second, lazybiggestseg[curin].second + lazybiggestseg[curin << 1 | 1].first);
    lazybiggestseg[curin << 1 | 1].first += lazybiggestseg[curin].first;
    lazybiggestseg[(curin << 1) + 2].second = max(lazybiggestseg[(curin << 1) + 2].second, lazybiggestseg[curin].second + lazybiggestseg[(curin << 1) + 2].first);
    lazybiggestseg[(curin << 1) + 2].first += lazybiggestseg[curin].first;
    lazybiggestseg[curin] = {0, 0};
}
void updatebig(int curin, int curl, int curr, int ql, int qr, int val)
{
    lazybiggest(curin, curl, curr);
    if (qr < curl || ql > curr)
        return;
    if (ql <= curl && curr <= qr)
    {
        lazybiggestseg[curin] = {val, val};
        lazybiggest(curin, curl, curr);
        return;
    }
    updatebig(curin << 1 | 1, curl, (curl + curr) >> 1, ql, qr, val), updatebig((curin << 1) + 2, ((curl + curr) >> 1) + 1, curr, ql, qr, val);
}
void querybig(int curin, int curl, int curr, int in)
{
    lazybiggest(curin, curl, curr);
    if (in < curl || in > curr)
        return;
    if (curl == curr)
        return;
    querybig(curin << 1 | 1, curl, (curl + curr) >> 1, in), querybig((curin << 1) + 2, ((curl + curr) >> 1) + 1, curr, in);
}

bool taped[maxq] = {}; // segid

vector<int> max_dist(vector<vector<int>> Coins)
{
    numcoin = Coins.size();
    for (int i = 0; i < numcoin; i++)
    {
        allcoin[i] = {Coins[i][0], Coins[i][2], Coins[i][1], i, -1};
        segcoin[i] = allcoin[i];
    }
    sort(segcoin, segcoin + numcoin, sortsize);
    for (int i = 0; i < numcoin; i++)
    {
        segcoin[i].segid = i;
        allcoin[segcoin[i].id].segid = i;
        sizonly[i] = segcoin[i].size;
    }
    for (int i = 0; i < numcoin; i++)
        startcoin[i] = allcoin[i];
    sort(startcoin, startcoin + numcoin, sortstart);
    buildmin(0, 0, numcoin - 1);
    updatemin(0, 0, numcoin - 1, 0, numcoin - 1, bignum);
    int curin = 0;
    vector<int> ans(numcoin, n);
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            for (int j = 0; j < tape; j++)
            {
                int pos = lesslower(rail[j]);
                if (pos >= 0)
                    updatebig(0, 0, numcoin - 1, 0, pos, 1);
            }
        else
        {
            int pos = lesslower(rail[i - 1]);
            if (pos >= 0)
                updatebig(0, 0, numcoin - 1, 0, pos, -1);
            if (i + tape - 1 < n)
            {
                int pos = lesslower(rail[i + tape - 1]);
                if (pos >= 0)
                    updatebig(0, 0, numcoin - 1, 0, pos, 1);
            }
        }
        if (curin < numcoin)
            while (startcoin[curin].start == i)
            {
                pair<int, int> tmp = querymin(0, 0, numcoin - 1, startcoin[curin].segid, startcoin[curin].segid);
                updatemin(0, 0, numcoin - 1, startcoin[curin].segid, startcoin[curin].segid, startcoin[curin].bounce - tmp.first);
                querybig(0, 0, numcoin - 1, startcoin[curin].segid);
                biggestarr[startcoin[curin].segid].second = biggestarr[startcoin[curin].segid].first;
                curin++;
                if (curin == numcoin)
                    break;
            }
        int pos = lesslower(rail[i]);
        if (pos >= 0)
            updatemin(0, 0, numcoin - 1, 0, pos, -1);
        pair<int, int> tmp = querymin(0, 0, numcoin - 1, 0, numcoin - 1);
        while (tmp.first == -1)
        {
            if (taped[tmp.second])
            {
                ans[segcoin[tmp.second].id] = i;
                updatemin(0, 0, numcoin - 1, tmp.second, tmp.second, bignum - 1);
            }
            else
            {
                taped[tmp.second] = 1;
                querybig(0, 0, numcoin - 1, tmp.second);
                updatemin(0, 0, numcoin - 1, tmp.second, tmp.second, biggestarr[tmp.second].second);
            }
            tmp = querymin(0, 0, numcoin - 1, 0, numcoin - 1);
        }
    }
    return ans;
}
