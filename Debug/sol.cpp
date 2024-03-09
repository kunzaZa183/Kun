#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 100000;
pair<int, int> lichao[8 * maxn];
int arr[maxn], allq[maxn];
vector<pair<int, int>> eachquery[maxn];
int findval(pair<int, int> a, int b)
{
  return a.first * b + a.second;
}
void update(int curin, int curl, int curr, int ql, int qr, pair<int, int> line)
{
  if (qr < curl || ql > curr)
    return;
  if (curl == curr)
  {
    if (findval(line, curl) < findval(lichao[curin], curl))
      lichao[curin] = line;
    return;
  }
  if (ql <= curl && curr <= qr)
  {
    int mid = (curl + curr) / 2;
    if (lichao[curin].first > line.first)
      swap(lichao[curin], line);
    if (findval(lichao[curin], curl) <= findval(line, curl))
      update(curin * 2 + 1, curl, mid, ql, qr, line);
    else
    {
      swap(lichao[curin], line);
      update(curin * 2 + 2, mid + 1, curr, ql, qr, line);
    }
    return;
  }
  update(curin * 2 + 1, curl, (curl + curr) / 2, ql, qr, line);
  update(curin * 2 + 2, (curl + curr) / 2 + 1, curr, ql, qr, line);
}
int query(int curin, int curl, int curr, int in)
{
  if (in < curl || in > curr)
    return LLONG_MAX;
  if (curl == curr)
    return findval(lichao[curin], in);
  return min(findval(lichao[curin], in), min(query(curin * 2 + 1, curl, (curl + curr) / 2, in), query(curin * 2 + 2, (curl + curr) / 2 + 1, curr, in)));
}
int32_t main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  fill(lichao, lichao + 8 * maxn, make_pair(INT_MAX, INT_MAX));
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  int qs;
  cin >> qs;
  for (int i = 0; i < qs; i++)
  {
    int a, b;
    cin >> a >> b;
    b--;
    eachquery[b].emplace_back(a, i);
  }
  int curheight = arr[0];
  for (int i = 0; i < n; i++)
  {
    curheight -= arr[i];
    update(0, 0, 2 * n - 1, n - i - 1, 2 * n - 1, {arr[i], curheight - arr[i] * (n - i - 1)});
    for (auto a : eachquery[i])
      allq[a.second] = query(0, 0, 2 * n - 1, n - i + a.first - 1) - curheight;
  }
  for (int i = 0; i < qs; i++)
    cout << allq[i] << '\n';
}