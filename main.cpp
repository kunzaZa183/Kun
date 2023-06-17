#include <bits/stdc++.h>
using namespace std;
struct trie
{
  int depth;
  trie *l, *r;
  trie()
  {
    depth = 0;
    l = nullptr, r = nullptr;
  }
} *root;
void addone(trie *cur, int add)
{
  if (cur->depth == 30)
    return;
  if (add & (30 - cur->depth))
  {
    if (cur->r == nullptr)
    {
      cur->r = new trie;
      cur->r->depth = cur->depth + 1;
    }
    addone(cur->r, add);
  }
  else
  {
    if (cur->l == nullptr)
    {
      cur->l = new trie;
      cur->l->depth = cur->depth + 1;
    }
    addone(cur->l, add);
  }
}
int closest(trie *cur, int num, int curi)
{
  if (cur->depth == 30)
    return num ^ curi;
  if (num & (1 << (30 - cur->depth)))
  {
    if (cur->r == nullptr)
      return closest(cur->l, num, curi);
    return closest(cur->r, num, curi + (1 << (30 - cur->r->depth)));
  }
  else
  {
    if (cur->l == nullptr)
      return closest(cur->r, num, curi + (1 << (30 - cur->r->depth)));
    return closest(cur->l, num, curi);
  }
}
pair<int, vector<int> *> smalltolarge(trie *cur)
{
  if (cur->l == nullptr && cur->r == nullptr)
    return {0, new vector<int>};
  if (cur->r == nullptr)
    return smalltolarge(cur->l);
  if (cur->l == nullptr)
    return smalltolarge(cur->r);
  auto zero = smalltolarge(cur->l), one = smalltolarge(cur->r);
  if (zero.second->size() > one.second->size())
  {
    int mini = INT_MAX;
    for (auto a : *one.second)
    {
      zero.second->push_back(a);
      mini = min(mini, closest(cur->l, a, 0));
    }
    if (mini == INT_MAX)
      mini = 0;
    return {zero.first + one.first + mini, zero.second};
  }
  else if (zero.second->size() <= one.second->size())
  {
    int mini = INT_MAX;
    for (auto a : *zero.second)
    {
      one.second->push_back(a);
      mini = min(mini, closest(cur->r, a, 0));
    }
    if (mini == INT_MAX)
      mini = 0;
    return {zero.first + one.first + mini, one.second};
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  while (n--)
  {
    int x;
    cin >> x;
    addone(root, x);
  }
  auto ans = smalltolarge(root);
  cout << ans.first << "\n";
}