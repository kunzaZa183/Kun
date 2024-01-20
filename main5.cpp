#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000;
int arr[2 * maxn], ct[maxn], inside[maxn];
map<int, int> mii;
queue<int> load[maxn];
int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    arr[i]--;
    ct[arr[i]]++;
  }
  vector<int> loading /*indices*/;
  queue<int> eaten;
  int boxes = 0, curnotate = 0;
  for (int i = 0; i < n; i++)
    if (inside[arr[i]] % k == 0)
    {
      if (boxes == m)
        eaten.push(i);
      else
      {
        boxes++;
        mii[arr[i]]++;
        curnotate++;
      }
    }
    else
    {
      load[arr[i]].push(i);
      inside[arr[i]]++;
      curnotate++;
    }
  for (int i = 0; i < n; i++)
  {
    mii[arr[i]]--;
    curnotate -= min(k, ct[arr[i]]);
    if (load[arr[i]].empty() && eaten.empty())
    {
    }
    else if (load[arr[i]].empty())
    {
      curnotate -= min(k * mii[eaten.front()], ct[eaten.front()]);
      mii[eaten.front()]++;
      curnotate += min(k * mii[eaten.front()], ct[eaten.front()]);
    }
    else if(eaten.empty())
    {
      mii[arr[i]]++;
    }
  }
}