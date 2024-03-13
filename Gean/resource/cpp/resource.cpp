#include <bits/stdc++.h>
#include "resource.h"
using namespace std;
#define int long long

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

void upd(treap *&sth)
{
  if (sth->l == NULL && sth->r == NULL)
    sth->siz = 0, sth->sum = sth->num;
  if (sth->l == NULL)
    sth->siz = sth->r->siz + 1, sth->sum = sth->num + sth->r->sum;
  if (sth->r == NULL)
    sth->siz = sth->l->siz + 1, sth->sum = sth->num + sth->l->sum;
  sth->siz = sth->l->siz + sth->r->siz + 1;
  sth->sum = sth->num + sth->l->sum + sth->r->sum;
}

void split(treap *target, treap *&l, treap *&r, int key)
{
  if (target == NULL)
    l = NULL, r = NULL;
  else if(target->num<=key)
  {
    target = l;
    
  }
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
}

void init_resource(int32_t N, int32_t Q, std::vector<int32_t> A, std::vector<int32_t> U, std::vector<int32_t> V, int32_t G)
{
  // edit this
  return;
}

long long need_help(int32_t X, int32_t C, int32_t K)
{
  // edit this
  return 0LL;
}