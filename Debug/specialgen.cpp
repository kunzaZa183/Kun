#include <bits/stdc++.h>
using namespace std;
int main()
{
  freopen("input.txt", "w", stdout);
  srand(time(NULL));
  const int n = 9, maxtype = 5, maxlen = 10;
  cout << n << '\n';
  mt19937 mt(time(0));
  vector<int> vi, vi2;
  for (int i = 1; i <= maxtype; i++)
  {
    vi.push_back(i);
    vi2.push_back(i);
  }
  for (int i = 0; i < n - maxtype; i++)
  {
    int pick = mt() % vi2.size();
    vi.push_back(vi2[pick]);
    vi2.erase(vi2.begin() + pick);
  }
  shuffle(vi.begin(), vi.end(), mt);
  for (auto a : vi)
    cout << a << ' ';
  cout << "\n";
  for (int i = 0; i < n; i++)
    cout << mt() % maxlen << " ";
  cout << "\n";
}