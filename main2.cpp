#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 500000;
int arr[maxn], idk[maxn];
int32_t main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  freopen("in.txt", "r", stdin);
  freopen("corr.txt", "w", stdout);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n - 1; j++)
      if (arr[j] > arr[j + 1])
        idk[j + 1] = arr[j + 1];
      else
        idk[j + 1] = arr[j];
    idk[0] = min(arr[n - 1], arr[0]);
    cout << accumulate(idk, idk + n, 0LL) << '\n';
    for (int i = 0; i < n; i++)
      arr[i] = idk[i];
  }
}