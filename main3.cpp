#include <bits/stdc++.h>
#define N 15005
using namespace std;
int fw[N][N]{0};
void add(int x, int y)
{
  for (int i = x; i < N; i += i & -i)
    for (int j = y; j < N; j += j & -j)
      fw[i][j]++;
}
int qr(int x, int y, int res = 0)
{
  for (int i = x; i; i -= i & -i)
    for (int j = y; j; j -= j & -j)
      res += fw[i][j];
  return res;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("in.txt", "r", stdin);
  int n;
  cin >> n;
  while (n--)
  {
    int p, h;
    cin >> p >> h;
    cout << qr(p - h + 5000, N - 1) - qr(p - h + 5000, p + h + 4999) << "\n";
    add(p - h + 5000, p + h + 5000);
  }
}