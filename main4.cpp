#include <bits/stdc++.h>
using namespace std;
int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  list<list<int>> li;
  li.push_back(list<int>(1, 1));
  li.push_back(list<int>(2, 3));
  auto it = find(li.begin(), li.end(), list<int>(1, 1));
  li.erase(it);
  if (it == li.end())
    cout << "HI\n";
  else
  {
    cout << it->size() << "\n";
    for (auto a : *it)
      cout << a << " ";
    cout << "\n";
  }
}