#include <bits/stdc++.h>
using namespace std;
int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  unordered_map<int,int> ctMp;
  ctMp.emplace(1,2);
  ctMp.emplace(2,3);
  ctMp.emplace(0,4);
  vector<pair<int, int>> sortedPairs(ctMp.begin(), ctMp.end());
  sort(sortedPairs.begin(), sortedPairs.end(), [](const auto &a, const auto &b)
       { return a.second > b.second; });
}