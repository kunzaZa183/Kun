#include "colorblind.h"
#include <bits/stdc++.h>
using namespace std;
const string tmp = "RB";
int findval(string &s)
{
  for(auto a:s)
}
bool check(string s, vector<int> diff)
{
  int ct = 0;
  for (auto a : s)
    if (a == 'R')
      ct++;
    else if (a == 'B')
      ct--;
  while (ct > 0)
  {
    s.push_back('B');
    ct--;
  }
  while (ct < 0)
  {
    s.push_back('R');
    ct++;
  }

}
string investivate_colors(int N)
{
  string ans;
  ans.push_back('R');
  vector<int> vi;
  for (int i = 0; i < 3; i++)
    for (int j = i + 1; j < 3; j++)
    {
      int x = use_device(i, j);
      vi.push_back(x);
    }
  vector<int> diff;
  for (int i = 0; i < vi.size(); i++)
    diff.push_back(vi[i + 1] - vi[i]);
  for (auto b : tmp)
    for (auto a : tmp)
    {
      ans.push_back(b);
      ans.push_back(a);

      ans.pop_back();
      ans.pop_back();
    }
}