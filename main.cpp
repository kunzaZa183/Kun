#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 200000;
int arr[maxn];
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
    sort(arr, arr + n);
    int l = 1, r = 1e11;
    while (l < r)
    {
      int mid = (l + r) / 2;
      int ct = 0;
      for (int i = 0; i < n; i++)
        if (arr[i] > mid)
        {
          ct++;
        }
      int total = 0;
      int maxi = 1;
      for (int i = 1; 1; i++)
      {
        total += i;
        if (total > mid)
        {
          total -= i;
          maxi = i;
          break;
        }
      }
      vector<int> vi;
      while (total != 0)
      {
        vi.push_back(total);
        total -= maxi++;
      }
      
    }
  }
}