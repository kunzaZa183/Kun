#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tests;
  cin >> tests;
  while (tests--)
  {
    int num;
    cin >> num;
    vector<int> vi(num);
    for (auto& a : vi)
      cin >> a;
    int pos = 0, neg = 0;
    for (auto a : vi)
      if (a > 0)
        pos++;
      else if (a < 0)
        neg++;
    vector<pair<int, int>> vpii;
    if (abs(pos - neg) <= 4)
    {
      int maxi = 0, maxid;
      for (int i = 0; i < num; i++)
        if (abs(vi[i]) > abs(maxi))
        {
          maxi = vi[i];
          maxid = i;
        }
      for (int i = 0; i < num; i++)
        if ((maxi < 0 && vi[i] > 0) || (maxi > 0 && vi[i] < 0))
          vpii.emplace_back(i, maxid);
      if (maxi < 0)
        for (int i = num - 2; i >= 0; i--)
          vpii.emplace_back(i, i + 1);
      else
        for (int i = 0; i < num - 1; i++)
          vpii.emplace_back(i + 1, i);
    }
    else if (pos > neg)
    {
      int theone;
      for (int i = 0; i < num; i++)
        if (vi[i] > 0)
        {
          theone = i;
          for (int j = 0; j < 5; j++)
            vpii.emplace_back(i, i);
          break;
        }
      for (int i = 0; i < num; i++)
        if (vi[i] < 0)
          vpii.emplace_back(i, theone);
      for (int i = 0; i < num - 1; i++)
        vpii.emplace_back(i + 1, i);
    }
    else if (pos < neg)
    {
      int theone;
      for (int i = 0; i < num; i++)
        if (vi[i] < 0)
        {
          theone = i;
          for (int j = 0; j < 5; j++)
            vpii.emplace_back(i, i);
          break;
        }
      for (int i = 0; i < num; i++)
        if (vi[i] > 0)
          vpii.emplace_back(i, theone);
      for (int i = num - 2; i >= 0; i--)
        vpii.emplace_back(i, i + 1);
    }
    cout << vpii.size() << '\n';
    for (auto a : vpii)
      cout << a.first + 1 << " " << a.second + 1 << "\n";
  }
}