#include <bits/stdc++.h>
using namespace std;
const int maxm = 1000000;
pair<int, int> arr[maxm];
int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, d, m;
  cin >> n >> d >> m;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i].first;
    arr[i].first--;
    arr[i].second = i;
  }
  sort(arr, arr + m);
  int l = 1, r = 2000000;
  while (l < r)
  {
    int mid = (l + r) / 2;
    int in = 0;
    for (int i = 0; i < n; i++)
    {
      if (arr[in].first < i - d)
        goto A;
      int ct = 0;
      while (ct < mid && in < m)
      {
        if (arr[in].first <= i)
        {
          ct++;
          in++;
        }
        else
          break;
      }
    }
    if (in == m)
    {
      r = mid;
      continue;
    }
  A:;
    l = mid + 1;
  }
  cout << l << "\n";
  int in2 = 0;
  for (int i = 0; i < n; i++)
  {
    int ct = 0;
    while (ct < l && in2 < m)
    {
      if (arr[in2].first <= i)
      {
        cout << arr[in2].second + 1 << ' ';
        ct++;
        in2++;
      }
      else
        break;
    }
    cout << "0\n";
  }
}