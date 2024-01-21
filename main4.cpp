#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000;
pair<int, int> arr[maxn];
int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i].first >> arr[i].second;
  sort(arr, arr + n, [](pair<int, int> a, pair<int, int> b)
       { return a.second < b.second; });
  int ct = 0;
  int cur = -1;
  for (int i = 0; i < n; i++)
    if (arr[i].first >= cur)
    {
      cur = arr[i].second;
      ct++;
    }
  cout << ct << '\n';
}