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
void addone(trie *cur, vector<int> &add)
{
  if (cur->depth == 30)
    return;
  if (add[cur->depth] == 0)
  {
    if (cur->l == nullptr)
    {
      cur->l = new trie;
      cur->l->depth = cur->depth + 1;
    }
    addone(cur->l, add);
  }
  else if (add[cur->depth] == 1)
  {
    if (cur->r == nullptr)
    {
      cur->r = new trie;
      cur->r->depth = cur->depth + 1;
    }
    addone(cur->r, add);
  }
}
pair<int, vector<vector<int> *> *> smalltolarge(trie *cur)
{
  vector<vector<int> *> *ret = new vector<vector<int> *>;
  if (cur == nullptr)
    return {0, ret};
  
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
}