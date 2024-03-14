#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 3000;
int arr[maxn];
int32_t main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    arr[i] -= i;
  }
  priority_queue<int> pqi;
  int lowest = 0;
  pqi.push(arr[0]);
  pqi.push(arr[0]);
  pqi.pop();
  for (int i = 1; i < n; i++)
  {
    // cout << lowest << '\n';
    if (pqi.top() <= arr[i])
    {
      pqi.push(arr[i]);
      pqi.push(arr[i]);
      pqi.pop();
    }
    else
    {
      lowest += pqi.top() - arr[i];
      pqi.push(arr[i]);
      pqi.push(arr[i]);
      pqi.pop();
    }
  }
  cout << lowest << "\n";
}