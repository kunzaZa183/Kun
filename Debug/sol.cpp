#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n, a, b, c, x;
  cin >> n >> a >> b >> c >> x;
  if (b > c)
    swap(b, c);
  int ways = 0;
  for (int i = 1; i <= n; i++)
  {
    int cur = x - i * a;
    int tmpb = b, tmpc = c;
    int gcdi = gcd(tmpb, tmpc);
    if (cur % gcdi != 0)
      continue;
    cur /= gcdi;
    tmpb /= gcdi, tmpc /= gcdi;
    int ansb, ansc;
    if (tmpb == 1)
    {
      ansb = 1;
      ansc = 0;
    }
    else
    {
      vector<pair<int, int>> vpii;
      vpii.emplace_back(tmpc, tmpb);
      while (vpii.back().second != 1)
        vpii.emplace_back(vpii.back().second, vpii.back().first % vpii.back().second);
      vpii.pop_back();
      ansb = 1;
      ansc = -(vpii.back().first - 1) / vpii.back().second;
      for (int j = vpii.size() - 2; j >= 0; j--)
      {
        ansb = ansc;
        ansc = (1 - ansb * vpii[j].first) / vpii[j].second;
      }
      swap(ansb, ansc);
    }
    int oldcur = cur;
    int down = cur / tmpb;
    cur %= tmpb;
    ansb *= cur, ansc *= cur;
    int tmp = 0;
    if (ansb < 0)
      tmp = (-ansb) / tmpc + 1;
    ansb += tmp * tmpc + down;
    ansc -= tmp * tmpb;
    int oldb = ansb;
    ansb %= tmpc;
    ansc += (oldb - ansb) / tmpc * tmpb;
    if (ansb == 0)
    {
      ansb += tmpc;
      ansc -= tmpb;
    }
    if (n >= ansc && ansc >= 1 && n >= ansb && ansb >= 1)
    {
      ways += max(min((ansc - 1) / tmpb + 1, (n - ansb) / tmpc + 1), 0LL);
    }
  }
  cout << ways << "\n";
}