#include "colorblind.h"
#include <bits/stdc++.h>
using namespace std;
string investivate_colors(int N)
{
  vector<int> vi;
  for (int i = 0; i < 3; i++)
    for (int j = i + 1; j < 3; j++)
    {
      int x = use_device(i, j);
      vi.push_back(x);
    }
  vector<int> diff;
  for (int i = 0; i < vi.size(); i++)
    diff.push_back(vi[i + 1] - vi[0]);
  vector<int> ans;
  if (diff == vector<int>{0, 0})
    ans = {1, 1, 1};
  else if (diff == vector<int>{-2, -2})
    ans = {1, 1, -1};
  else if (diff == vector<int>{0, 2})
    ans = {1, -1, 1};
  else if (diff == vector<int>{2, 0})
    ans = {1, -1, -1};
  int pref = 0;
  for (int i = 3; i < 2 * N; i++)
  {
    pref += ans[i - 3];
    
  }
}