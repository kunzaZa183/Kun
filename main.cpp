#include <bits/stdc++.h>
using namespace std;
int block;
struct state
{
  int l, r, in;
  bool operator<(state x)
  {
    if (l / block != x.l / block)
      return l < x.l;
    return r < x.r;
  }
};
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> val(n+1);
  val[0]=0;
  for (int i=1;i<=n;i++)
    cin >> val[i];
  vector<state> vst(m);
  for (int i = 0; i < m; i++)
  {
    cin >> vst[i].l >> vst[i].r;
    vst[i].l--, vst[i].r--;
    vst[i].in = i;
  }
  block = sqrt(n);
  sort(vst.begin(),vst.end());

}