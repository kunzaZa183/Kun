#include <bits/stdc++.h>
#include "resource.h"
using namespace std;
#define int long long
const int maxn = 100000, logk = 15;
mt19937 mt;
struct treap
{
  int num, prior, siz, sum;
  treap *l, *r;
  treap()
  {
    num = 0;
    prior = mt();
    l = NULL, r = NULL;
    siz = 0;
  }
} above, cur;

int cursiz(treap *target)
{
  if (target == NULL)
    return 0;
  return target->siz;
}

int cursum(treap *target)
{
  if (target == NULL)
    return 0;
  return target->sum;
}

void upd(treap *&sth)
{
  sth->siz = cursiz(sth->l) + cursiz(sth->r) + 1;
  sth->sum = sth->num + cursum(sth->l) + cursum(sth->r);
}

void split(treap *target, treap *&l, treap *&r, int key)
{
  if (target == NULL)
    l = NULL, r = NULL;
  else if (target->num >= key)
  {
    l = target;
    split(target->r, target->r, r, key);
  }
  else if (target->num < key)
  {
    r = target;
    split(target->l, l, r->l, key);
  }
  upd(target);
}

void merge(treap *&target, treap *l, treap *r)
{
  if (l == NULL && r == NULL)
    return;
  if (l == NULL)
    target = r;
  if (r == NULL)
    target = l;
  if (l->prior > r->prior)
  {
    target = l;
    merge(target->r, l->r, r);
  }
  else if (l->prior < r->prior)
  {
    target = r;
    merge(target->l, l, r->l);
  }
  else if (l->prior == r->prior)
  {
    int a = 0;
    while (1)
      a++;
  }
  upd(target);
}

//(0,k-1)
int findsum(treap *target, int k)
{
  if (target == NULL)
    return 0;
  if (k == 0)
    return 0;
  if (cursiz(target->l) >= k)
    return findsum(target->l, k);
  if (cursiz(target->l) == k)
    return cursum(target->l);
  return cursum(target->l) + target->num + findsum(target->r, k - 1 - cursiz(target->l));
}

void init_resource(int32_t N, int32_t Q, std::vector<int32_t> A, std::vector<int32_t> U, std::vector<int32_t> V, int32_t G)
{
  return;
}

long long need_help(int32_t X, int32_t C, int32_t K)
{
  // edit this
  return 0LL;
}