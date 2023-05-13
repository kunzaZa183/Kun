#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  set<int> mii;
  mii.insert(1);
  set<int> *si = &mii;
  cout << *si->begin() << '\n';
  for (int i = 1; i <= 1000; i++)
    mii.insert(i);
  cout << *si->rbegin() << '\n';
}