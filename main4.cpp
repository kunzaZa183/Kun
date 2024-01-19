#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 100000;
int arr[maxn], goright[maxn], goleft[maxn], dir[maxn];
signed main()
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
    memset(goright, 0, sizeof goright);
    memset(goleft, 0, sizeof goleft);
    for (int i = 1; i < n - 1; i++)
      if (dir[i])
        goright[i] = arr[i + 1] - arr[i] - 1;
      else
        goleft[i] = arr[i] - arr[i - 1] - 1;
    goright[0] = arr[1] - arr[0] - 1;
    goleft[n - 1] = arr[n - 1] - arr[n - 2] - 1;
    for (int i = 1; i < n; i++)
    {
      goright[i] += goright[i - 1];
      goleft[i] += goleft[i - 1];
    }
    int qs;
    cin >> qs;
    while (qs--)
    {
      int a, b;
      cin >> a >> b;
      a--, b--;
      if (a < b)
        cout << arr[b] - arr[a] - (goright[b - 1] - goright[a - 1]) << '\n';
      else if (b < a)
        cout << arr[a] - arr[b] - (goleft[a] - goleft[b]) << "\n";
    }
  }
}