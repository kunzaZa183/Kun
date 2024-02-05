#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000;
bool segtree[4 * maxn][4 * maxn];
int n, m;
void updatey(int inx, int curiny, int curl, int curr, int lefty, int righty)
{
  if (curr < lefty && righty < curl)
    return;
  if (lefty <= curl && curr <= righty)
  {
    segtree[inx][curiny] = 1;
    return;
  }
  updatey(inx, curiny * 2, curl, (curl + curr) / 2, lefty, righty);
  updatey(inx, curiny * 2 + 1, (curl + curr) / 2 + 1, curr, lefty, righty);
  segtree[inx][curiny] = segtree[inx][curiny * 2] && segtree[inx][curiny * 2 + 1];
}
void updatex(int curin, int curl, int curr, int leftx, int rightx, int topy, int boty)
{
  if (curr < leftx || curl > rightx)
    return;
  if (leftx <= curl && curr <= rightx)
  {
    updatey(curin, 1, 0, m - 1, topy, boty);
    if(segtree[curin][1])
      segtree[curin][0] = 1;
  }
  updatex(curin * 2 + 1, curl, (curl + curr) / 2, leftx, rightx, topy, boty);
  updatex(curin * 2 + 2, (curl + curr) / 2 + 1, curr, leftx, rightx, topy, boty);
  
  segtree[curin][0] = segtree[curin * 2 + 1][0] && segtree[curin * 2 + 2][0];
}
int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tests;
  cin >> tests;
  while (tests--)
  {
    memset(segtree, 0, sizeof segtree);
    cin >> n >> m;
    int k;
    cin >> k;
    int reached = 100000;
    for (int i = 0; i < k; i++)
    {
      int x, y, r;
      cin >> x >> y >> r;
      updatex(0, 0, n - 1, x - r, x + r, y - r, y + r);
      if (segtree[0][0] == n * m)
      {
        reached = min(reached, i);
      }
    }
    if (reached == 100000)
      cout << "-1\n";
    else
      cout << reached << '\n';
  }
}