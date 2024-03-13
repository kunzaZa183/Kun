#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 500000;
int arr[maxn], idk[maxn];
vector<int> vi;
list<list<int>> ldi;
int32_t main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  // freopen("in.txt","r",stdin);
  // freopen("out.txt","w",stdout);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  int maxi = INT_MAX, minid = -1;
  for (int i = 0; i < n; i++)
    if (arr[i] < maxi)
    {
      maxi = arr[i];
      minid = i;
    }
  list<int> tmp;
  for (int i = minid; i < n; i++)
    vi.push_back(arr[i]);
  for (int i = 0; i < minid; i++)
    vi.push_back(arr[i]);
  for (auto a : vi)
  {
    if (tmp.empty())
      tmp.push_back(a);
    else if (tmp.back() > a)
    {
      ldi.push_back(tmp);
      tmp.clear();
      tmp.push_back(a);
    }
    else
      tmp.push_back(a);
  }
  ldi.push_back(tmp);
  int cursum = accumulate(vi.begin(), vi.end(), 0LL);
  vector<list<list<int>>::iterator> qi;
  for (auto it = ldi.begin(); it != ldi.end(); it++)
    qi.push_back(it);
  for (int i = 0; i < n; i++)
  {
    vector<list<list<int>>::iterator> more;
    for (auto a : qi)
    {
      if (a->empty())
        continue;
      if (a->back() == a->front())
        continue;
      cursum -= a->back();
      cursum += a->front();
      a->pop_back();
      a->push_front(a->front());
      more.push_back(a);
    }
    vector<list<list<int>>::iterator> works;
    for (auto a : more)
    {
      if (a != ldi.begin())
      {
        auto it = a;
        it--;
        if (it->back() <= a->front())
          continue;
      }
      works.push_back(a);
    }
    for (auto a : works)
    {
      auto it = a;
      it++;
      while (it != ldi.end())
      {
        if (a->back() <= it->front())
        {
          a->splice(a->end(), *it);
          it = ldi.erase(it);
        }
        else
          break;
      }
    }
    qi.swap(works);
    cout << cursum << "\n";
  }
}