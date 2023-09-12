#include "cheatsheet.h"
#include <bits/stdc++.h>
using namespace std;
#define BASE 350'001
struct bignum
{
  vector<int> num;
  bignum()
  {
  }
  bignum(int num)
  {
    this->num.push_back(num);
  }
  friend bignum operator+(bignum a, bignum b)
  {
    bignum ret(0);
    reverse(a.num.begin(), a.num.end());
    reverse(b.num.begin(), b.num.end());
    for (int i = 0; i < max(a.num.size(), b.num.size()); i++)
    {
      int first = 0, second = 0;
      if (i < a.num.size())
        first = a.num[i];
      if (i < b.num.size())
        second = b.num[i];
      ret.num.back() += first + second;
      ret.num.push_back(ret.num.back() / BASE);
      ret.num[ret.num.size() - 2] %= BASE;
    }
    return ret;
  }
  friend bignum operator-(bignum a, bignum b)
  {
    bignum ret;
    for (int i = 0; i < a.num.size(); i++)
      if (i >= b.num.size())
        ret.num.push_back(a.num[i]);
      else
        ret.num.push_back(a.num[i] - b.num[i]);
    for (int i = 0; i < a.num.size() - 1; i++)
      if (a.num[i] < 0)
      {
        a.num[i] += BASE;
        a.num[i + 1]--;
      }
    reverse(ret.num.begin(), ret.num.end());
    return ret;
  }
  friend bignum operator*(bignum a, bignum b)
  {
    vector<bignum> ret;
    for (int i = b.num.size() - 1; i >= 0; i--)
    {
      bignum sth(0);
      for (int j = 0; j < a.num.size(); j++)
      {
        sth.num.back() += b.num[i] * a.num[j];
        sth.num.push_back(sth.num.back() / BASE);
        sth.num[sth.num.size() - 2] %= BASE;
      }
      reverse(sth.num.begin(), sth.num.end());
      for (int j = 0; j < b.num.size() - 1 - i; j++)
        sth.num.push_back(0);
      ret.push_back(sth);
    }
    for (int i = 1; i < ret.size(); i++)
      ret[i] = ret[i] + ret[i - 1];
    return ret.back();
  }
  friend bool operator<(bignum a, bignum b)
  {
    a.recheck(), b.recheck();
    if (a.num.size() > b.num.size())
      return 0;
    if (a.num.size() < b.num.size())
      return 1;
    for (int i = 0; i < a.num.size(); i++)
    {
      if (a.num[i] < b.num[i])
        return 1;
      else if (a.num[i] > b.num[i])
        return 0;
    }
    return 0;
  }
  void recheck()
  {
    reverse(num.begin(), num.end());
    while (num.back() == 0 && num.size() > 1)
      num.pop_back();
    reverse(num.begin(), num.end());
  }
};

vector<int> write_cheatsheet(int N, vector<int> A)
{
  bignum last;
  last.num = A;

  vector<int> vi;
  for (int i = 0; i <= 1067; i++)
    vi.push_back(i);

  vector<bignum> fact;
  fact.emplace_back(1);
  for (int i = 1; i <= 1068; i++)
    fact.push_back(fact.back() * bignum(i));

  vector<int> ans;
  for (int i = 0; i <= 1067; i++)
  {
    int in = 0;
    while (!(last < fact[1067 - i]))
      last = last - fact[1067 - i];
    ans.push_back(vi[in]);
    vi.erase(vi.begin() + in);
  }
  return ans;
}

vector<int> recover_answer(int N, vector<int> R)
{
  vector<bignum> fact;
  fact.emplace_back(1);
  for (int i = 1; i <= 1068; i++)
    fact.push_back(fact.back() * bignum(i));

  vector<int> vi;
  for (int i = 0; i <= 1067; i++)
    vi.push_back(i);

  bignum res(0);
  for (int i = 0; i < R.size(); i++)
  {
    res = res + fact[R.size() - i - 1] * bignum(find(vi.begin(), vi.end(), R[i]) - vi.begin());
    vi.erase(find(vi.begin(), vi.end(), R[i]));
  }

  return res.num;
}
