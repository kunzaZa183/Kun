#include <bits/stdc++.h>
using namespace std;
int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  string s;
  cin >> s;
  string order;
  string ourstack;
  for (int i = s.size() - 1; i >= 0; i--)
    if (s[i] == ')')
      ourstack.push_back(')');
    else if (s[i] == '(')
    {
      string tmp;
      while (ourstack.back() != ')')
      {
        tmp.push_back(ourstack.back());
        ourstack.pop_back();
      }
      ourstack.pop_back();
      for (int j = tmp.size() - 1; j >= 0; j--)
        order.push_back(tmp[j]);
    }
    else if (s[i] == '|')
    {
      while (!ourstack.empty())
        if (ourstack.back() == '|')
        {
          order.push_back('|');
          ourstack.pop_back();
          break;
        }
        else if (ourstack.back() == '&')
        {
          order.push_back('&');
          ourstack.pop_back();
        }
        else
          break;
      ourstack.push_back('|');
    }
    else if (s[i] == '&')
    {
      if (ourstack.empty())
        ourstack.push_back('&');
      else if (ourstack.back() == '&')
        order.push_back('&');
      else
        ourstack.push_back('&');
    }
  for (int i = ourstack.size() - 1; i >= 0; i--)
    order.push_back(ourstack[i]);
  for (int i = 0; i < order.size(); i++)
  {
    if (i != 0)
      cout << " ";
    cout << order[i];
  }
}