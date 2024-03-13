#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000,k = 20;
set<int> adjlist[maxn];
bitset<maxn> dead;
int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n,m;
  cin>>n>>m;
  for(int i=0;i<m;i++)
  {
    int a,b;
    cin>>a>>b;
    adjlist[a].insert(b),adjlist[b].insert(a);
  }
  for(int i=0;i<n;i++)
    if(adjlist[i].size()>k)
    {
      dead[i] = 1;
    }
}