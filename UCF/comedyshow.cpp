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
    int comedians, lower, upper;
    cin >> comedians >> lower >> upper;
    lower -= comedians * (comedians + 1) / 2, upper -= comedians * (comedians + 1) / 2;
    lower = max(lower, 0);
    vector<vector<int>> vvi(26, vector<int>(1001, 0)); // can do 0
    vvi[0][0] = 1;
    for (int i = 1; i < 25; i++)
    {
      for (int j = 0; j < 1001; j++)
      {
        for (int k = 0; k < j; k++)
          vvi[i][j] += vvi[i - 1][j - k] + ;
      }
    }
  }
}