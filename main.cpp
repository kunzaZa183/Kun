#include <bits/stdc++.h>
using namespace std;
const int maxm = 500, maxn = 1000001;
vector<int> vi[maxm];
int adjmatrix[maxm][maxm];
vector<int> all[maxn];
int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int x;
    cin >> x;
    vi[i].resize(x);
    for (auto &a : vi[i])
    {
      cin >> a;
      all[a].push_back(i);
    }
  }
  for(int i=0;i<m;i++)
    for(int j=0;j<m;j++)
      adjmatrix[i][j] = 1e9;
  for()
  for (int i = 0; i < n; i++)
    for (int j = 0; j < all[i].size(); j++)
      for (int k = j + 1; k < all[i].size(); k++)
        adjmatrix[all[i][j]][all[i][k]] = 1, adjmatrix[all[i][k]][all[i][j]] = 1;
  for(int i=0;i<m;i++)
    for(int j=i+1;j<m;j++)
      for(int k=0;k<m;k++)
        if(k!=i && k!=j)
        {
         if(adjmatrix[i][k] + adjmatrix[k][j]<)
        }
}