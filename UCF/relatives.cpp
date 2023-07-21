#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>
using namespace std;
vector<vector<double>> dp, vvd;
int n;

double recur(int in, int visited)
{
  if (in == 0 & visited != 1)
    return INT_MAX;
  if (dp[in][visited] == INT_MAX)
  {
    for (int i = 0; i < n; i++)
      if ((1 << i) & visited && i!=in)
        dp[in][visited] = min(dp[in][visited], recur(i, visited ^ (1 << in)) + vvd[i][in]);
  }
  return dp[in][visited];
}
int main()
{
  int tests;
  cin >> tests;
  while (tests--)
  {
    cin >> n;
    vvd.clear();
    vvd.resize(n, vector<double>(n));
    for (auto& a : vvd)
      for (auto& b : a)
        cin >> b;
    dp.clear();
    dp.resize(n, vector<double>((1 << n), INT_MAX));
    dp[0][1] = 0;
    double mini = INT_MAX;
    for (int i = 1; i < n; i++)
      mini = min(mini, recur(i, ((1 << n) - 1)) + vvd[i][0]);
    cout << fixed << setprecision(2) << mini << '\n';
  }
}