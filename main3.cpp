#include <bits/stdc++.h>
using namespace std;
const int maxn = 300000;
int arr[maxn], ans[maxn];
vector<pair<int, int>> vpii;
int val;
int exists(set<int> &target)
{
  auto it = target.lower_bound(val);
  if (it == target.begin() || it == target.end())
    return INT_MAX;
  auto it2 = it;
  it2--;
  return *it - *it2 + 1;
}
int checkbef(set<int> &idk, int in)
{
  auto it = idk.lower_bound(in);
  if (it == idk.begin())
    return INT_MAX;
  it--;
  return in - *it + 1;
}
int checkaft(set<int> &idk, int in)
{
  auto it = idk.lower_bound(in);
  if (it == idk.end())
    return INT_MAX;
  return *it + 1 - in + 1;
}
int cur[maxn];
int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  set<int> oddmore, oddless, evenless, evenmore;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    vpii.emplace_back(arr[i], i);
    if (i % 2 == 0)
      evenmore.insert(i);
    else
      oddmore.insert(i);
    cur[i] = 1;
  }

  set<int> nextevenmore, nextevenless, nextoddmore, nextoddless;
  sort(vpii.begin(), vpii.end());
  for (int i = 0; i < n - 1; i++)
    if (i % 2 == 0)
      nextevenmore.insert(i);
    else
      nextoddmore.insert(i);

  for (auto a : vpii)
  {
    val = a.second;
    if (a.second % 2 == 0)
      evenmore.erase(a.second);
    else
      oddmore.erase(a.second);
    ans[a.second] = min(min(exists(evenmore), exists(oddmore)), min(exists(evenless), exists(oddless)));
    // if (a.first == 7)
    // {
    //   cout << exists(evenmore) << ' ' << exists(oddmore) << " " << exists(evenless) << " " << exists(oddless) << "\n";
    // }
    if (a.second % 2 == 0)
      evenless.insert(a.second);
    else
      oddless.insert(a.second);
    if (a.second != 0)
    {
      if (cur[a.second - 1] == 1)
      {
        if ((a.second - 1) % 2 == 0)
          nextevenmore.erase(a.second - 1);
        else
          nextoddmore.erase(a.second - 1);
      }
    }
    if (a.second != n - 1)
    {
      if (cur[a.second + 1] == 1)
      {
        if (a.second % 2 == 0)
          nextevenmore.erase(a.second);
        else
          nextoddmore.erase(a.second);
      }
    }
    if (a.second % 2 == 0)
    {
      ans[a.second] = min(ans[a.second], min(checkbef(nextevenless, a.second), checkbef(nextevenmore, a.second)));
      ans[a.second] = min(ans[a.second], min(checkaft(nextoddless, a.second), checkaft(nextoddmore, a.second)));
    }
    else
    {
      ans[a.second] = min(ans[a.second], min(checkaft(nextevenless, a.second), checkaft(nextevenmore, a.second)));
      ans[a.second] = min(ans[a.second], min(checkbef(nextoddless, a.second), checkbef(nextoddmore, a.second)));
    }

    if (a.second != 0)
    {
      if (cur[a.second - 1] == -1)
      {
        if ((a.second - 1) % 2 == 0)
          nextevenless.insert(a.second - 1);
        else
          nextoddless.insert(a.second - 1);
      }
    }
    if (a.second != n - 1)
    {
      if (cur[a.second + 1] == -1)
      {
        if (a.second % 2 == 0)
          nextevenless.insert(a.second);
        else
          nextoddless.insert(a.second);
      }
    }
    cur[a.second] = -1;
  }
  for (int i = 0; i < n; i++)
    if (ans[i] == INT_MAX)
      cout << "-1 ";
    else
      cout << ans[i] << " ";
  cout << "\n";
}