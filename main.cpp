#include "sort_weight.h"
#include <bits/stdc++.h>
using namespace std;
void sort_init()
{
  vector<int> vi;
  int x = sort_weight(0, 1);
  if (x == -1)
    vi.push_back(0), vi.push_back(1);
  if (x == 1)
    vi.push_back(1), vi.push_back(0);
  for (int i = 0; i < 2; i++)
  {
    x = sort_weight(2, vi[i]);
    if (x == -1)
    {
      vi.insert(vi.begin() + i, 2);
      break;
    }
  }
  x = sort_weight(3, 4);
  vector<int> vi2;
  if (x == -1)
    vi2.push_back(3), vi2.push_back(4);
  else
    vi2.push_back(4), vi2.push_back(3);
  x = sort_weight(vi2[0], vi[0]);
  if (x == -1)
  {
    vi.insert(vi.begin(), vi2[0]);
    x = sort_weight(vi[2], vi2[1]);
    if (x == -1)
    {
      x = sort_weight(vi[3], vi2[1]);
      if (x == -1)
        vi.push_back(vi2[1]);
      else if (x == 1)
        vi.insert(vi.begin() + 3, vi2[1]);
    }
    else if(x==1)

  }
}