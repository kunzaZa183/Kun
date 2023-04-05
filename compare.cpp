#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  ifstream in("text1.txt");
  streambuf *cinbuf = cin.rdbuf(); // save old buf
  cin.rdbuf(in.rdbuf());                // redirect std::cin to in.txt!
  vector<string> vs1;
  string s;
  while (cin >> s)
    vs1.push_back(s);
  cin.rdbuf(cinbuf);

  ifstream in2("text2.txt");
  cin.rdbuf(in2.rdbuf());
  vector<string> vs2;
  while (cin >> s)
    vs2.push_back(s);
  for (int i = 0; i < vs1.size(); i++)
    if (vs1[i] != vs2[i])
      cerr << "Conflict on line : " << i << '\n';
  cout << "DONE\n";
}