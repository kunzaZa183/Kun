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

int query(int curin, int curl, int curr)
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

map<int, int> parnextroot[maxn];

int curnextroot;
void dfs3(int cur, int par)
{
	parnextroot[curcent][cur] = curnextroot;
	for (auto a : adjlist[cur])
		if (!used[a] && a != par)
			dfs3(a, cur);
}

multiset<int> allans, alldowncent[maxn];
int oldans[maxn];

int sumfirsttwo(multiset<int>& msi)
{
	auto it = msi.rbegin(), it2 = msi.rbegin();
	it2++;
	return *it + *it2;
}

void eachcent(int cur, int siz, int oldcent)
{
	dfs1(cur, -1);

	numintree = siz;
	int cent = dfs2(cur, -1);

	parcent[cent] = oldcent;

	timer = 0;
	curcent = cent;
	segtree[cent].resize(4 * siz), lazy[cent].resize(4 * siz);
	eulertour(cent, -1, 0);

	alldowncent[cent].insert(0), alldowncent[cent].insert(0);
	for (auto a : adjlist[cent])
	{
		ql = starttime[cent][a], qr = endtime[cent][a] - 1;
		alldowncent[cent].insert(query(0, 0, siz - 1));
		curnextroot = a;
		dfs3(a, cent);
	}
	oldans[cent] = sumfirsttwo(alldowncent[cent]) + arr[cent];
	allans.insert(oldans[cent]);

	used[cent] = 1;
	for (auto a : adjlist[cent])
		if (!used[a])
			eachcent(a, ::siz[a], cent);
}