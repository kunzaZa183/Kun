#include <bits/stdc++.h>
using namespace std;
int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  freopen("input.txt", "w", stdout);
  srand(time(NULL));
  const int n = 5, maxtype = 2;
  cout << n << '\n';
  mt19937 mt(time(0));
  vector<int> vi,vi2;
  for (int i = 1; i <= maxtype; i++)
  {
    vi.push_back(i);
    vi2.push_back(i);
  }
  for (int i = 0; i < n - maxtype; i++)
  {
    int pick = mt % vi2.size();
    
  }
}