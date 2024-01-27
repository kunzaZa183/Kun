#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 100000;
int arr[maxn], goleft[maxn], goright[maxn];
multiset<int> froml, fromr;
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
    for (int i = 0; i < n; i++)
    {
      goleft[i] = arr[i] - (n - i);
      goright[i] = arr[i] - (i + 1);
    }
    froml.clear(), fromr.clear();
    froml.insert(goleft[0]);
    for (int i = 2; i < n; i++)
      fromr.insert(goright[i]);
    int maxi = INT_MIN;
    for (int i = 1; i < n - 1; i++)
    {
      maxi = max(maxi, arr[i] + *froml.rbegin() + *fromr.rbegin());
      froml.insert(goleft[i]);
      fromr.erase(fromr.find(goright[i + 1]));
    }
    cout << maxi + n + 1 << "\n";
  }
}