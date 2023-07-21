#include <bits/stdc++.h>
using namespace std;
#define double long double
double dist(pair<double, double> a, pair<double, double> b)
{
  return sqrt(abs(a.first - b.first) * abs(a.first - b.first) + abs(a.second - b.second) * abs(a.second - b.second));
}
double slope(pair<double, double> a, pair<double, double> b)
{
  return (b.second - a.second) / (b.first - a.first);
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (1)
  {
    pair<double, double> points[4];
    for (int i = 0; i < 4; i++)
      cin >> points[i].first >> points[i].second;
    for (int i = 0; i < 4; i++)
      if (abs(points[i].first - 0.0) > 1e-6)
        goto A;
    return 0;
  A:
    pair<double, double> intersect;
    double slope1 = slope(points[0], points[2]), slope2 = slope(points[1], points[3]);
    double c1 = points[0].second - slope1 * points[0].first,c2 = points[1].second - slope2 *points[2].second;
  }
}