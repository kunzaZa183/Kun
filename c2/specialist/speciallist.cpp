#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> children;
const int MOD = 1000000007;
struct node
{
  pair<int, int> key;
  int priority;
  node* l, * r;
  int sumofsubtree, subtreesiz;
  node()
  {
    l = NULL, r = NULL;
    priority = rand() * RAND_MAX + rand();
    sumofsubtree = 0;
    subtreesiz = 1;
  }
};
int sumof(node* cur)
{
  if (cur == NULL)
    return 0;
  return cur->sumofsubtree;
}
int sizof(node* cur)
{
  if (cur == NULL)
    return 0;
  return cur->subtreesiz;
}
void split(node* cur, node*& l, node*& r, pair<int, int> key)
{
  if (cur == NULL)
  {
    l = NULL, r = NULL;
    return;
  }
  if (cur->key <= key)
  {
    split(cur->r, cur->r, r, key);
    l = cur;
  }
  else if (cur->key > key)
  {
    split(cur->l, l, cur->l, key);
    r = cur;
  }
  cur->subtreesiz = sizof(cur->l) + sizof(cur->r) + 1;
  cur->sumofsubtree = sumof(cur->l) + sumof(cur->r) + cur->key.first;
}
void merge(node*& target, node* l, node* r)
{
  if (l == NULL && r == NULL)
  {
    target = NULL;
    return;
  }
  if (l == NULL)
    target = r;
  else if (r == NULL)
    target = l;
  else if (l->priority > r->priority)
  {
    merge(l->r, l->r, r);
    target = l;
  }
  else if (l->priority <= r->priority)
  {
    merge(r->l, l, r->l);
    target = r;
  }
  target->subtreesiz = sizof(target->l) + sizof(target->r) + 1;
  target->sumofsubtree = sumof(target->l) + sumof(target->r) + target->key.first;
}
node* leftmost(node* cur)
{
  while (cur->l != NULL)
    cur = cur->l;
  return cur;
}
struct retval
{
  node* head;
  int val;
  retval()
  {
    val = 0;
    head = NULL;
  }
};
vector<int> qsum, zvi, each;
vector<int32_t> ans;
int eachz;
retval* dfs(int cur)
{
  vector<retval*> vr;
  retval* maxi = new retval;
  for (auto a : children[cur])
  {
    vr.push_back(dfs(a));
    if (sizof(vr.back()->head) > sizof(maxi->head))
      maxi = vr.back();
  }
  int curval = 0;
  int lower = lower_bound(zvi.begin(), zvi.end(), each[cur]) - zvi.begin();
  int lowsum = 0;
  if (lower != 0)
    lowsum = qsum[lower - 1];
  maxi->val = (maxi->val + (each[cur] * lower - lowsum) % MOD) % MOD;
  maxi->val = (maxi->val + ((qsum.back() - lowsum) - (zvi.size() - lower) * each[cur]) % MOD) % MOD;
  for (auto a : vr)
    if (a != maxi)
    {
      maxi->val = (maxi->val + a->val) % MOD;
      vector<node*> vn;
      while (a->head != NULL)
      {
        node* tmp = leftmost(a->head);
        split(a->head, tmp, a->head, tmp->key);
        node* tmp2 = new node;
        split(maxi->head, maxi->head, tmp2, tmp->key);
        maxi->val = (maxi->val + (tmp->key.first * sizof(maxi->head) - sumof(maxi->head)) % MOD) % MOD;
        maxi->val = (maxi->val + (sumof(tmp2) - tmp->key.first * sizof(tmp2)) % MOD) % MOD;
        merge(maxi->head, maxi->head, tmp2);
        vn.push_back(tmp);
      }
      for (auto a : vn)
      {
        node* tmp = new node;
        split(maxi->head, maxi->head, tmp, a->key);
        merge(maxi->head, maxi->head, a);
        merge(maxi->head, maxi->head, tmp);
      }
    }
  node* tmp = new node;
  tmp->key = { each[cur], cur };
  tmp->sumofsubtree = each[cur];
  node* tmp2 = new node;
  split(maxi->head, maxi->head, tmp2, tmp->key);
  maxi->val = (maxi->val + (each[cur] * sizof(maxi->head) - sumof(maxi->head)) % MOD) % MOD;
  maxi->val = (maxi->val + (sumof(tmp2) - each[cur] * sizof(tmp2)) % MOD) % MOD;
  merge(maxi->head, maxi->head, tmp);
  merge(maxi->head, maxi->head, tmp2);
  ans[cur] = (maxi->val + eachz) % MOD;
  return maxi;
}
vector<int32_t> compute_cost(int32_t n, int32_t m, vector<int32_t> P, vector<int32_t> X, vector<int32_t> Z)
{
  children.resize(n);
  for (int i = 1; i < P.size(); i++)
    children[P[i]].push_back(i);
  for (auto a : Z)
    zvi.push_back(a);
  for (auto& a : zvi)
    a = a * a;
  sort(zvi.begin(), zvi.end());
  qsum = zvi;
  for (int i = 1; i < qsum.size(); i++)
    qsum[i] += qsum[i - 1];
  ans.resize(n);
  for (auto& a : X)
    each.push_back(a);
  for (auto& a : each)
    a = a * a;
  for (int i = 1; i < m - 1; i++)
    eachz = (eachz + (zvi[i] * i - (qsum[i - 1])) % MOD) % MOD;
  eachz = (eachz + (m * zvi.back() - qsum.back()) % MOD) % MOD;
  dfs(0);
  return ans;
}
