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
  for (int i = 0; i < vi.size() - 1; i++)
    diff.push_back(vi[i + 1] - vi[0]);
  vector<int> ans;
  int normal;
  if (diff == vector<int>{0, 0})
  {
    ans = {1, 1, 1};
    normal = vi[0];
  }
  else if (diff == vector<int>{-2, -2})
  {
    ans = {1, 1, -1};
    normal = vi[0];
  }
  else if (diff == vector<int>{0, 2})
  {
    ans = {1, -1, 1};
    normal = vi[1];
  }
  else if (diff == vector<int>{2, 0})
  {
    ans = {1, -1, -1};
    normal = vi[2];
  }
  int pref = 0;
  for (int i = 3; i < 2 * N; i++)
  {
    pref += ans[i - 3];
    if (ans[i - 1] == 1 && ans[i - 2] == 1)
    {
      int x;
      if (pref >= 0)
        x = use_device(i - 1, i);
      else if (pref == -1)
        x = use_device(i - 2, i);
      else if (pref <= -2)
        x = use_device(i - 2, i);
      if (x == normal)
        ans.push_back(1);
      else
        ans.push_back(-1);
    }
    else if (ans[i - 1] == -1 && ans[i - 2] == -1)
    {
      int x;
      if (pref <= 0)
        x = use_device(i - 1, i);
      else if (pref == 1)
        x = use_device(i - 2, i);
      else if (pref >= 2)
        x = use_device(i - 2, i);
      if (x == normal)
        ans.push_back(-1);
      else
        ans.push_back(1);
    }
    else if (ans[i - 1] == -1 && ans[i - 2] == 1)
    {
      int x;
      if (pref >= 0)
      {
        x = use_device(i - 1, i);
        x -= 2;
      }
      else if (pref <= -1)
        x = use_device(i - 2, i);
      if (x == normal)
        ans.push_back(1);
      else
        ans.push_back(-1);
    }
    else if (ans[i - 1] == 1 && ans[i - 2] == -1)
    {
      int x;
      if (pref <= 0)
      {
        x = use_device(i - 1, i);
        x -= 2;
      }
      else if (pref >= 1)
        x = use_device(i - 2, i);
      if (x == normal)
        ans.push_back(-1);
      else
        ans.push_back(1);
    }
  }
  string s;
  for (auto a : ans)
    if (a == 1)
      s.push_back('R');
    else if (a == -1)
      s.push_back('B');
  return s;
}