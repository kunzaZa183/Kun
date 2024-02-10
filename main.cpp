#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 200000, MOD = 998244353;
int arr[maxn];
vector<int> adjlist[maxn];
int total = 0;
map<int, int> *sack(int cur, int par)
{
  if (adjlist[cur].size() == 1 && cur != 0)
  {
    map<int, int> *tmp = new map<int, int>;
    total++;
    tmp->emplace(arr[cur], 1);
    return tmp;
  }
  vector<map<int, int> *> vmii;
  for (auto a : adjlist[cur])
    if (a != par)
      vmii.push_back(sack(a, cur));
  map<int, int> *maxi = vmii.front();
  for (int i = 1; i < vmii.size(); i++)
    if (vmii[i]->size() > maxi->size())
      maxi = vmii[i];
  total++;
  total %= MOD;
  for (auto a : vmii)
    if (a->count(arr[cur]))
    {
      total += a->at(arr[cur]);
      total %= MOD;
    }
  map<int, vector<int>> mii;
  for (auto a : vmii)
    if (a != maxi)
      for (auto b : *a)
        mii[b.first].push_back(b.second);
  for (auto &a : mii)
  {
    if (maxi->count(a.first))
      a.second.push_back(maxi->at(a.first));
    int total = 1, sum = 0;
    for (auto b : a.second)
    {
      total *= b + 1;
      total %= MOD;
      sum += b;
      sum %= MOD;
    }
    total--;
    total += MOD;
    total %= MOD;
    total -= sum;
    total += MOD;
    total %= MOD;
    ::total += total;
    ::total %= MOD;
  }
  for (auto a : vmii)
    if (a != maxi)
      for (auto b : *a)
      {
        maxi->operator[](b.first) += b.second + maxi->operator[](b.first) * b.second % MOD;
        maxi->operator[](b.first) %= MOD;
      }
  maxi->operator[](arr[cur])++;
  return maxi;
}
signed main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  for (int i = 0; i < n - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    adjlist[a - 1].push_back(b - 1);
    adjlist[b - 1].push_back(a - 1);
  }
  if(n==1)
  {
    cout<<"1\n";
    return 0;
  }
  sack(0, 0);
  cout << total << '\n';
}