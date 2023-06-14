#include <bits/stdc++.h>
using namespace std;
int main()
{
  // ios::sync_with_stdio(0);
  // cin.tie(0);
  freopen("in.txt", "w", stdout);
  int n = 10;
  cout << n << '\n';
  vector<int> vi(n);
  srand(time(NULL));
  for (int i = 0; i < n; i++)
  {
    vi[i] = rand() % 5+1;
    cout << vi[i] << ' ';
  }
  sort(vi.begin(), vi.end());
  cout << "\n";
  int qs = 30;
  cout << qs << '\n';
  for (int i = 0; i < qs; i++)
  {
    int type = rand() % 2;
    cout << type + 1 << " ";
    if (type == 0)
      cout << rand() % n+1 << ' ' << rand() % n+1 << '\n';
    else if (type == 1)
      cout << rand() % n+1 << ' ' << rand() % n+1 << ' ' << vi[rand() % vi.size()] << '\n';
  }
}