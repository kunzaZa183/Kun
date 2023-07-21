#include <bits/stdc++.h>
using namespace std;
struct trie
{
  int ct;
  map<char, trie> mct;
  trie()
  {
    ct = 0;
  }
  void add(string &s, int in)
  {
    ct++;
    if (in == s.size())
      return;
    mct[s[in]].add(s, in + 1);
  }
  int query(string &s, int in)
  {
    if (in == s.size())
      return ct;
    return mct[s[in]].query(s, in + 1);
  }
};
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tests;
  cin >> tests;
  int ct = 0;
  while (tests--)
  {
    bool cur = 1;
    cout << "Lottery #" << ++ct << ":\n";
    trie root, revroot;
    int qs;
    cin >> qs;
    while (qs--)
    {
      int type;
      cin >> type;
      if (type == 1)
      {
        string s;
        cin >> s;
        string rev(s);
        reverse(rev.begin(), rev.end());
        if (cur)
        {
          root.add(s, 0);
          revroot.add(rev, 0);
        }
        else
        {
          root.add(rev, 0);
          revroot.add(s, 0);
        }
      }
      else if (type == 2)
      {
        string s;
        cin >> s;
        string rev(s);
        reverse(rev.begin(), rev.end());
        if (cur)
          cout << root.query(s, 0) << '\n';
        else
          cout << revroot.query(s, 0) << "\n";
      }
      else if (type == 3)
        cur = !cur;
    }
    // if (tests > 0)
    cout << '\n';
  }
}