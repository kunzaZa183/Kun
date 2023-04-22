// #include "pointlib.h"
#include <bits/stdc++.h>
using namespace std;

static int n;
static int x[10010];
static int y[10010];

int point_init()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d %d", &x[i], &y[i]);
  return n;
}

int query(int i, int j)
{
  return ((x[i] > x[j] ? x[i] - x[j] : x[j] - x[i]) +
          (y[i] > y[j] ? y[i] - y[j] : y[j] - y[i]));
}

int main()
{
  int n = point_init();
  int x = query(0, 1);
  if (n == 2)
  {
    cout << "0 0\n";
    cout << x - 1 << " 1\n";
    return 0;
  }
  vector<pair<int, int>> vpii(n, {INT_MAX, INT_MAX});
  vpii[0] = {0, 0};
  for (int i = 2; i < n; i++)
  {
    int y = query(1, i), z = query(0, i);
    if (x > y && x > z)
    {
      if (y + z == x)
      {
        vpii[1] = {x, 0};
        vpii[i] = {z, 0};
      }
      else if (y + z == x + 2)
      {
        vpii[1] = {x, 0};
        vpii[i] = {z - 1, 1};
      }
      else if (y + z == x + 1)
        vpii[1] = {x - 1, 1};
    }
    else if (y > x && y > z)
    {
      // assume that vpii[1] is to the right
      if (x + z == y)
      {
        vpii[1] = {x, 0};
        vpii[i] = {-z, 0};
      }
      else if(x+z==y+1)
      {
        .
        
      }
    }
  }
}