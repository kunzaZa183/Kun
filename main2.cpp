#include <bits/stdc++.h>
using namespace std;
int main()
{
  // ios::sync_with_stdio(0);
  // cin.tie(0);
  int tests;
  cin >> tests;
  // freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  while (tests--)
  {
    cerr << "INSERT NUM = ";
    string s;
    cin >> s;
    int a, b;
    cin >> a >> b;
    vector<int> vi;
    for (auto a : s)
      if (isalpha(a))
        vi.push_back(a - 'A' + 10);
      else
        vi.push_back(a - '0');
    int val = 0;
    int i = 0;
    for (auto x : vi)
    {
      cout << x << "*" << a << '^' << vi.size() - i - 1;
      if (i != vi.size() - 1)
        cout << " + ";
      val *= a;
      val += x;
      i++;
    }
    cout << " = " << val << " = ";
    string second;
    while (val != 0)
    {
      int num = val % b;
      if (num >= 10)
        second.push_back(num - 10 + 'A');
      else
        second += to_string(num);
      val /= b;
    }
    reverse(second.begin(), second.end());
    for (int i = 0; i < second.size(); i++)
    {
      cout << second[i] << "*" << b << "^" << second.size() - i - 1;
      if (second.size() - 1 != i)
        cout << " + ";
    }
    cout << " = " << second << " in base " << b << '\n';
  }
}