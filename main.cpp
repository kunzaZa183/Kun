#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 200000;
int arr[maxn];
int32_t main()
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
    sort(arr, arr + n);
    int l = 1, r = n;
    while (l < r)
    {
      int mid = (l + r) / 2;
      vector<int> vi;
      int total = mid;
      int tmpmid = mid;
      while (tmpmid > 0)
      {
        vi.push_back(total);
        tmpmid--;
        total += tmpmid;
      }
      bool pass = 0;
      for (int i = 0; i < n - 1; i++)
      {
        if (pass)
          break;
        int pos = i - (upper_bound(vi.begin(), vi.end(), arr[i]) - vi.begin());
        if (pos == n - mid - 1)
          pass = 1;
      }
      if (pass)
        r = mid;
      else
        l = mid + 1;
    }
    cout << min(arr[n - 1], l * (l + 1) / 2) << "\n";
  }
}