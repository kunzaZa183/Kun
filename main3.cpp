#include <bits/stdc++.h>
using namespace std;
int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  mt19937 mt(time(NULL));
  cout << mt();
  vector<int> vi;
  shuffle(vi.begin(), vi.end(), mt);
}