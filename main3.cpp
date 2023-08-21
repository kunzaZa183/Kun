#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> vi(n);
  set<int> mustread;
  vector<int> ans;
  queue<int> books;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    vi[i].resize(x);
    for (auto &a : vi[i])
    {
      cin >> a;
      a--;
    }
  }
  for (int i = 0; i < vi[0].size(); i++)
    books.push(vi[0][i]);
  while (!books.empty())
  {
    int add = books.front();
    books.pop();
    if (!mustread.count(add))
    {
      mustread.insert(add);
      ans.push_back(add);
      for (auto a : vi[add])
        books.push(a);
    }
  }
  reverse(ans.begin(), ans.end());
  for (auto a : ans)
    cout << a + 1 << ' ';
  cout << '\n';
}