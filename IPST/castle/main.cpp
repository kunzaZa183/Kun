#include <bits/stdc++.h>
#include "castle.h"
using namespace std;

int N, M, Q, Y;
vector<int> A, B;

const int maxn = 100000, maxm = 100009;
int dsu[maxn];

int find(int cur)
{
  if (dsu[cur] == cur)
    return cur;
  dsu[cur] = find(dsu[cur]);
  return dsu[cur];
}

vector<pair<int, int>> special;
vector<int> adjlist[maxn];
int mapped[maxn], depth[maxn];
bitset<maxm> bsm;

int visiti = 0;
void dfs(int cur, int par, int d)
{
  mapped[cur] = visiti;
  depth[visiti] = d;
  visiti++;
  for (auto a : adjlist[cur])
    if (a != par)
      dfs(a, cur, d + 1);
}

set<int> newadj[maxn];

struct node
{
  int val, prior;
  node* l, * r, * par;
  node(int x)
  {
    this->val = x;
    l = NULL, r = NULL, par = NULL;
    prior = rand() * RAND_MAX + rand();
  }
};

void merge(node*& tar, node* l, node* r, node* par)
{
  if (l == NULL && r == NULL)
    return;
  if (l == NULL)
  {
    r->par = par;
    tar = r;
  }
  else if (r == NULL)
  {
    l->par = par;
    tar = l;
  }
  else if (l->prior > r->prior)
  {
    merge(l->r, l->r, r, l);
    l->par = par;
    tar = l;
  }
  else if (l->prior <= r->prior)
  {
    merge(r->l, l, r->l, r);
    r->par = par;
    tar = r;
  }
}

void split(node* tar, node*& l, node*& r, int key, node* parl, node* parr) // leq key = left; morethan key = right
{
  if (tar == NULL)
  {
    l = NULL, r = NULL;
    return;
  }
  if (tar->val <= key)
  {
    split(tar->r, tar->r, r, key, tar, parr);
    tar->par = parl;
    l = tar;
  }
  else if (tar->val > key)
  {
    split(tar->l, l, tar->l, key, parl, tar);
    tar->par = parr;
    r = tar;
  }
}

node* head(node* cur)
{
  while (cur->par != NULL)
    cur = cur->par;
  return cur;
}

node* arrnode[maxn];

int main()
{
  castle_init(N, M, Q, Y);
  castle_read_map(A, B);

  for (int i = 0; i < N; i++)
    dsu[i] = i;

  for (int i = 0; i < M; i++)
  {
    if (find(A[i]) == find(B[i]))
    {
      bsm[i] = 1;
      special.emplace_back(A[i], B[i]);
    }
    else
    {
      adjlist[A[i]].push_back(B[i]), adjlist[B[i]].push_back(A[i]);
      dsu[find(A[i])] = find(B[i]);
    }
  }

  dfs(0, 0, 0);

  for (auto& a : special)
    a.first = mapped[a.first], a.second = mapped[a.second];

  for (int i = 0; i < N; i++)
    for (auto a : adjlist[i])
      newadj[mapped[i]].insert(mapped[a]);

  node* head = NULL;
  for (int i = 0; i < N; i++)
  {
    node* tmp = new node(i);
    arrnode[i] = tmp;
    merge(head, head, tmp, NULL);
  }
  while (Q--)
  {
    int T, X, Y;
    castle_read_event(T, X, Y);
    if (T == 1)
    {
      if (bsm[X])
        special.erase(find(special.begin(), special.end(), make_pair(A[X], B[X])));
      else
      {
        int a = mapped[A[X]], b = mapped[B[X]];
        if (depth[a] > depth[b])
          swap(a, b);
        node* tmp = NULL, * tmp2 = NULL, * tmp3 = NULL;
        auto it = newadj[a].upper_bound(b);
        int left = b - 1, right;
        if (it == newadj[a].end())
          right = INT_MAX;
        else
          right = *it - 1;
        tmp = ::head(arrnode[a]);
        split(tmp, tmp, tmp2, left, NULL, NULL);
        split(tmp2, tmp2, tmp3, right, NULL, NULL);
        merge(tmp, tmp, tmp3, NULL);
        newadj[a].erase(b), newadj[b].erase(a);
      }
    }
    else if (T == 2)
    {
      X = ::head(arrnode[mapped[X]])->val, Y = ::head(arrnode[mapped[Y]])->val;
      if (X == Y)
        castle_answer(1);
      else
      {
        set<int> si;
        si.insert(X), si.insert(Y);
        vector<pair<int, int>> vpii;
        for (auto a : special)
        {
          vpii.emplace_back(::head(arrnode[a.first])->val, ::head(arrnode[a.second])->val);
          si.insert(vpii.back().first), si.insert(vpii.back().second);
        }
        for (auto a : si)
          dsu[a] = a;
        for (auto a : vpii)
          dsu[find(a.first)] = find(a.second);
        if (find(X) == find(Y))
          castle_answer(1);
        else
          castle_answer(0);
      }
    }
  }
}
