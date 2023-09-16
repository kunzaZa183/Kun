#include <bits/stdc++.h>
using namespace std;
struct query
{
  int l, r, val;
};
const int BIGM = 600003;
int seg[BIGM];

void update(int x, long long val){
	while(x<=m){
		seg[x]+=val;
		//[x]=min(tree[x],maxi);
		x+=(x&-x);
	}
}
long long read(int x){
	long long s=0;
	while(x>0){
		s+=tree[x];
		//s=min(tree[x],maxi);
		x-=(x&-x);
	}
	return s;
}
 
void apply(int x){
	if(ql[x]<=qr[x])
		update(ql[x],qa[x]),update(qr[x]+1,-qa[x]);
	else{
		update(1,qa[x]);
		update(qr[x]+1,-qa[x]);
		update(ql[x],qa[x]);
	}
}

signed main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> owns(n);
  for (int i = 0; i < m; i++)
  {
    int x;
    cin >> x;
    x--;
    owns[x].push_back(i);
  }
  vector<int> should(n);
  for (auto &a : should)
    cin >> a;
  int qs;
  cin >> qs;
  vector<query> vq(qs);
  for (auto &a : vq)
  {
    cin >> a.l >> a.r >> a.val;
    a.l--, a.r--;
  }
  vector<int> bsl(n, 1), bsr(n, qs);
  vector<bool> works(n, 0);
  vector<int> same(n, 0);
  while (1)
  {
    vector<pair<int, int>> vpii; // mid index
    for (int i = 0; i < n; i++)
      if (bsl[i] < bsr[i])
        vpii.emplace_back((bsl[i] + bsr[i]) / 2, i);
      else if (same[i] == 0)
      {
        same[i]++;
        vpii.emplace_back((bsl[i] + bsr[i]) / 2, i);
      }
    if (vpii.empty())
      break;
    sort(vpii.begin(), vpii.end());

    memset(seg, 0, sizeof seg);
    int in = 0;
    for (int i = 0; i < qs; i++)
    {
      if (vq[i].l <= vq[i].r)
        update(vq[i].l + 1, vq[i].r + 1, vq[i].val, m);
      else
      {
        update(vq[i].l + 1, m, vq[i].val, m);
        update(1, vq[i].r + 1, vq[i].val, m);
      }
      while (vpii[in].first == i + 1)
      {
        unsigned long long total = 0;
        for (auto a : owns[vpii[in].second])
          total += qry(a + 1, m);
        if (total >= should[vpii[in].second])
        {
          bsr[vpii[in].second] = vpii[in].first;
          works[vpii[in].second] = 1;
        }
        else
          bsl[vpii[in].second] = vpii[in].first + 1;
        in++;
        if (in == vpii.size())
          goto A;
      }
    }
  A:;
  }
  for (int i = 0; i < n; i++)
    if (!works[i])
      cout << "NIE\n";
    else
      cout << bsl[i] << "\n";
}