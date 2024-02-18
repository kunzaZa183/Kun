#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 500000;
int arr[maxn];
vector<int> allnum;
struct node
{
  int val;
  node *bef, *next;
  node(int x)
  {
    val = x;
    bef = NULL, next = NULL;
  }
};
struct List
{
  node *head, *last;
  List()
  {
    head = NULL, last = NULL;
  }
  void push_back(int num)
  {
    if (head == NULL)
    {
      head = new node(num);
      last = head;
      return;
    }
    node *tmp = new node(num);
    tmp->bef = last;
    last->next = tmp;
    last = tmp;
  }
  void pop_back()
  {
    last = last->bef;
    last->next = NULL;
  }
  friend void operator+(List &a, List &b)
  {
    a.last->next = b.head;
    b.head->bef = a.last;
  }
  void push_front(int num)
  {
    node *tmp = new node(num);
    tmp->next = head;
    head->bef = tmp;
    head = tmp;
  }
};
signed main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  int mini = INT_MAX, minid = -1;
  for (int i = 0; i < n; i++)
    if (arr[i] < mini)
    {
      mini = arr[i];
      minid = i;
    }
  for (int i = minid; i < n; i++)
    allnum.push_back(arr[i]);
  for (int i = 0; i < minid; i++)
    allnum.push_back(arr[i]);
  vector<List *> vl;
  List *tmp = new List;
  for (int i = 0; i < allnum.size(); i++)
    if (tmp->head == NULL)
      tmp->push_back(allnum[i]);
    else if (allnum[i] >= tmp->last->val)
      tmp->push_back(allnum[i]);
    else
    {
      vl.push_back(tmp);
      tmp = new List;
      tmp->push_back(allnum[i]);
    }
  if (tmp->head != NULL)
    vl.push_back(tmp);
  list<List *> lli;
  for (auto a : vl)
    if (a->head->val != a->last->val)
      lli.push_back(a);
  int sum = accumulate(arr, arr + n, 0LL);
  for (int i = 0; i < n; i++)
  {
    for (auto it = lli.begin(); it != lli.end();)
    {
      sum -= ((*it)->last->val - (*it)->head->val);
      (*it)->push_front((*it)->last->val);
      (*it)->pop_back();
      if ((*it)->head->val == (*it)->last->val)
        it = lli.erase(it);
      else
        it++;
    }
    
    cout << sum << '\n';
  }
}