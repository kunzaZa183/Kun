#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000;
bitset<maxn> dir;
int arr[maxn], dsu[maxn];
int other[maxn];
int find(int cur)
{
  if (dsu[cur] == cur)
    return cur;
  dsu[cur] = find(dsu[cur]);
  return dsu[cur];
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
      cin >> arr[i];
    dir[0] = 1;
    dir[n - 1] = 0;
    for (int i = 1; i < n - 1; i++)
      dir[i] = arr[i] - arr[i - 1] > arr[i + 1] - arr[i];
    for (int i = 0; i < n; i++)
      dsu[i] = i;
    for (int i = 0; i < n; i++)
      if (dir[i])
        dsu[find(i)] = dsu[find(i + 1)];
      else
        dsu[find(i)] = dsu[find(i - 1)];
    memset(other, -1, sizeof other);
    for (int i = 0; i < n; i++)
      if (find(i) == i)
      {
        if (dir[i])
          other[i] = i + 1;
        else
          other[i] = i - 1;
      }

    int qs;
    cin >> qs;
    while (qs--)
    {
      int a, b;
      cin >> a >> b;
      a--, b--;
      int ct = 0;
    A:
      if (a < b)
      {
        if (dir[a])
        {
          a++;
          ct++;
          goto A;
        }
      }
      else if (b < a)
      {
        if (!dir[a])
        {
          a--;
          ct++;
          goto A;
        }
      }
      cout << ct + abs(arr[a] - arr[b]) << '\n';
    }
  }
}