#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000;
vector<int> adjlist[maxn];
int dist[maxn], par[maxn];
int maxi, maxid;
void dfs(int cur, int par, int dis)
{
  // cout << "CUR: " << cur << " " << par << "\n";
  dist[cur] = dis;
  if (dis > maxi)
  {
    maxi = dis;
    maxid = cur;
  }
  ::par[cur] = par;
  for (auto a : adjlist[cur])
    if (a != par)
      dfs(a, cur, dis + 1);
}
int deepest(int cur, int par)
{
  int maxi = 0;
  for (auto a : adjlist[cur])
    if (a != par)
      maxi = max(maxi, deepest(a, cur));
  return maxi + 1;
}
int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tests;
  cin >> tests;
  while (tests--)
  {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
      adjlist[i].clear();
    for (int i = 0; i < n - 1; i++)
    {
      int a, b;
      cin >> a >> b;
      a--, b--;
      adjlist[a].push_back(b);
      adjlist[b].push_back(a);
    }
    maxi = 0, maxid = 0;
    dfs(0, 0, 0);
    // cout << "OUT\n";
    int tmp = maxid;
    // cout << tmp << "\n";
    maxi = 0, maxid = tmp;
    dfs(tmp, tmp, 0);
    vector<int> vi;
    while (par[maxid] != maxid)
    {
      vi.push_back(maxid);
      maxid = par[maxid];
    }
    // for (auto a : vi)
    //   cout << a << " ";
    // cout << "\n";
    vi.push_back(tmp);
    // for (auto a : vi)
    //   cout << a << " ";
    // cout << "\n";
    // cout << "SIZ = " << vi.size() << "\n";
    if (vi.size() % 2 == 1)
    {
      cout << vi.size() / 2 + 1 << "\n";
      for (int i = 0; i <= vi.size() / 2; i++)
        cout << vi[vi.size() / 2] + 1 << ' ' << i << "\n";
    }
    else if (vi.size() % 4 == 2)
    {
      cout << vi.size() / 2 + 1 << "\n";
      for (int i = 0; i <= vi.size() / 2; i++)
        cout << vi[vi.size() / 2] + 1 << ' ' << i << "\n";
    }
    else
    {
      int num = vi.size() / 2 - 1, num2 = vi.size() / 2;
      int max1 = 0, max2 = 0;
      for (int i = num; i > vi.size() / 4; i--)
        for (auto a : adjlist[vi[i]])
          if (a != vi[i - 1] && a != vi[i + 1])
            max1 = max(max1, deepest(a, vi[i]) + num - i + 1);

      for (int i = num2; i < num + vi.size() / 4; i++)
        for (auto a : adjlist[vi[i]])
          if (a != vi[i - 1] && a != vi[i + 1])
            max2 = max(max2, deepest(a, vi[i]) + i - num2 + 1);
      cout << max1 << " " << max2 << "\n";
      if (max1 == vi.size() / 2 && max2 == vi.size() / 2)
      {
        cout << vi.size() / 2 + 1 << "\n";
        for (int i = 0; i <= vi.size() / 2; i++)
          cout << vi[vi.size() / 2] + 1 << ' ' << i << "\n";
      }
      else if (max1 == vi.size() / 2)
      {
        cout << vi.size() / 2 << "\n";
        for (int i = 1; i < vi.size() / 2; i++)
          cout << vi[vi.size() / 2 - 1] + 1 << ' ' << i << "\n";
        cout << vi[num2 + vi.size() / 4 - 1] + 1 << ' ' << vi.size() / 4 << "\n";
      }
      else if (max2 == vi.size() / 2)
      {
        cout << vi.size() / 2 << "\n";
        for (int i = 1; i < vi.size() / 2; i++)
          cout << vi[vi.size() / 2] + 1 << ' ' << i << "\n";
        cout << vi[vi.size() / 4] + 1 << ' ' << vi.size() / 4 << "\n";
      }
      else
      {
        cout << vi.size() / 2 << "\n";
        for (int i = 1; i < vi.size() / 2; i++)
          cout << vi[vi.size() / 2] + 1 << ' ' << i << "\n";
        cout << vi[vi.size() / 4] + 1 << ' ' << vi.size() / 4 << "\n";
      }
    }
  }
}