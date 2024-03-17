#include <bits/stdc++.h>
using namespace std;
/*
Problem Name: Palindrome Queries
Problem Link: https://cses.fi/problemset/task/2420
Author: Sachin Srivastava (mrsac7)
*/
#define int long long
#define endl '\n'

const int md = 1e9 + 7;
int B = 73; // Sheldon prime (lol)
const int mxN = 2e5 + 6;
int pB[mxN];
struct
{
  int bit[mxN] = {0};

  void update(int k, int x)
  {
    x %= md;
    if (x < md)
      x += md;
    for (; k < mxN; k += k & -k)
    {
      (bit[k] += x) %= md;
    }
  }

  int query(int k)
  {
    int s = 0;
    for (; k > 0; k -= k & -k)
      (s += bit[k]) %= md;
    return s;
  }
} pre, suf;

string s;
const int maxn = 200000;
int to[maxn];
signed main()
{
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  B = uniform_int_distribution<int>(73, 7337)(rng);
  pB[0] = 1;
  for (int i = 1; i < mxN; i++)
    pB[i] = pB[i - 1] * B % md;
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tests;
  cin >> tests;
  while (tests--)
  {
    // cout << "X\n";
    memset(pre.bit, 0, sizeof pre.bit);
    memset(suf.bit, 0, sizeof suf.bit);
    int n, q;
    cin >> n >> q;
    cin >> s;
    // cout << "THISA\n";
    for (int i = 0; i < n; i++)
    {
      pre.update(i + 1, (s[i] - 'a' + 1) * pB[i]);
      suf.update(i + 1, (s[i] - 'a' + 1) * pB[n - i - 1]);
    }
    // cout << "THIS\n";
    vector<int> vi;
    for (int i = 0; i < s.size(); i++)
    {
      if (vi.empty())
        vi.push_back(i);
      else if (s[vi.back()] == s[i])
        vi.push_back(i);
      else
      {
        for (auto a : vi)
          to[a] = i - 1;
        vi.clear();
        vi.push_back(i);
      }
    }
    if (!vi.empty())
      for (auto a : vi)
        to[a] = n - 1;
    while (q--)
    {
      int a, b;
      cin >> a >> b;
      a--, b--;
      if (to[a] == to[b])
        cout << "0\n";
      else
      {
        // cout << "HERE?\n";
        int sth = b - a;
        int x = a + 1, y = b + 1;
        int h1 = (pre.query((x + y) / 2) - pre.query(x - 1) + md) % md;
        int m1 = pB[x - 1];
        int h2 = (suf.query(y) - suf.query((x + y - 1) / 2) + md) % md;
        int m2 = pB[n - y];
        int ans = sth * (sth + 1) / 2 + sth;
        if (h1 * m2 % md == h2 * m1 % md)
          ans -= sth + 1;
        cout << ans << "\n";
      }
    }
  }
}