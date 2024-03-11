#include <bits/stdc++.h>
using namespace std;
int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  list<int> li;
  li.push_back(1);
  li.insert(li.end(), 2);
  cout << li.back() << "\n";
}