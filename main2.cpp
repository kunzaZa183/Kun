#include <iostream>
#include <string>
#include <vector>
using namespace std;
string all[9] = {"ABDE", "ABC", "BCEF", "ADG", "BDEFH", "CFI", "DEGH", "GHI", "EFHI"};
int arr[9] = {}, sth[9];
vector<int> res;
int len = 30000;
void recur(int in)
{
  if (in == 9)
  {
    int tmp[9];
    for (int i = 0; i < 9; i++)
      tmp[i] = arr[i];
    for (int i = 0; i < 9; i++)
      for (int j = 0; j < all[i].size(); j++)
        tmp[all[i][j] - 'A'] += sth[i];
    for (int i = 0; i < 9; i++)
      if (tmp[i] % 4 != 0)
        return;
    vector<int> all;
    for (int i = 0; i < 9; i++)
      for (int j = 0; j < sth[i]; j++)
        all.push_back(i + 1);
    if (all.size() < len)
    {
      res = all;
      len = all.size();
    }
    return;
  }
  for (int i = 0; i < 4; i++)
  {
    sth[in] = i;
    recur(in + 1);
  }
}
int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  for (int i = 0; i < 9; i++)
    cin >> arr[i];
  recur(0);
  for (int i = 0; i < res.size(); i++)
    cout << res[i] << ' ';
  cout << "\n";
}