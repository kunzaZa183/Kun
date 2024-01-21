#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000;
int arr[maxn];
int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  freopen("race.in", "r", stdin);
  freopen("race.out", "w", stdout);
  int k, n;
  cin >> k >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  for (int i = 0; i < n; i++)
  {
    int curwalked = 0;
    int mini = INT_MAX;
    for (int speed = 1; 1; speed++)
    {
      curwalked += speed;
      int mightwalk = curwalked;
      if (speed <= arr[i])
      {
        if (mightwalk > k)
          break;
        else
          mini = min(mini, speed + (k - mightwalk + (speed - 1)) / speed);
      }
      else if (speed > arr[i])
      {
        int high = speed - 1;
        int low = arr[i];
        mightwalk += (high - low + 1) * (high + low) / 2;
        if (mightwalk <= k)
          mini = min(mini, speed + (speed - arr[i]) + (k - mightwalk + (speed - 1)) / speed);
        else if (mightwalk > k)
          break;
      }
    }
    cout << mini << '\n';
  END:;
  }
}