#include <bits/stdc++.h>
using namespace std;
vector<int> status;
int sood(int cur)
{
  if (status[cur] == -1)
    return cur;
  if (status[cur] == status.size())
    return status.size();
  status[cur] = sood(status[cur]);
  return status[cur];
}
vector<int> seg;
void update(int curin, int curl, int curr, int qin, int val)
{
  if (curl == curr && curl == qin)
  {
    seg[curin] = val;
    return;
  }
  if (qin < curl || qin > curr)
    return;
  update(curin * 2 + 1, curl, (curl + curr) / 2, qin, val), update(curin * 2 + 2, (curl + curr) / 2 + 1, curr, qin, val);
  seg[curin] = seg[curin * 2 + 1] + seg[curin * 2 + 2];
}
int query(int curin, int curl, int curr, int ql, int qr)
{
  if (ql <= curl && curr <= qr)
    return seg[curin];
  if (qr < curl || curr < ql)
    return 0;
  return query(curin * 2 + 1, curl, (curl + curr) / 2, ql, qr) + query(curin * 2 + 2, (curl + curr) / 2 + 1, curr, ql, qr);
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  string s;
  cin >> s;
  status.resize(n, -1);
  vector<int> importance;
  while (m--)
  {
    int l, r;
    cin >> l >> r;
    l--, r--;
    while (l <= r)
      if (status[l] == -1)
      {
        status[l] = r + 1;
        importance.push_back(l);
        l++;
      }
      else
        l = sood(l);
  }
  int numzer = 0;
  for (auto a : s)
    if (a == '0')
      numzer++;
  vector<int> mapped(n, -1);
  seg.resize(4 * importance.size());
  for (int i = 0; i < importance.size(); i++)
  {
    mapped[importance[i]] = i;
    update(0, 0, importance.size() - 1, i, s[importance[i]] - '0');
  }
  while (q--)
  {
    int x;
    cin >> x;
    x--;
    if (s[x] == '0')
    {
      s[x] = '1';
      numzer--;
    }
    else
    {
      s[x] = '0';
      numzer++;
    }
    if (mapped[x] != -1)
      update(0, 0, importance.size() - 1, mapped[x], s[x] - '0');
    int canbe1 = n - numzer;
    if (canbe1 > importance.size())
      canbe1 = importance.size();
    else if (canbe1 == 0)
    {
      cout << "0\n";
      continue;
    }
    cout << canbe1 - query(0, 0, importance.size() - 1, 0, canbe1 - 1) << "\n";
  }
}