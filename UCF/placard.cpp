#include <bits/stdc++.h>
using namespace std;
vector<tuple<long long, long long, long long>> seg; // min mincount lazy
void lazyv(long long curin)
{
  auto &[a, b, c] = seg[curin];
  a += c;
  if (curin * 2 + 1 < seg.size())
    get<2>(seg[curin * 2 + 1]) += c;
  if (curin * 2 + 2 < seg.size())
    get<2>(seg[curin * 2 + 2]) += c;
  c = 0;
}
void build(long long curin, long long curl, long long curr)
{
  if (curl == curr)
  {
    seg[curin] = {0, 1, 0};
    return;
  }
  build(curin * 2 + 1, curl, (curl + curr) / 2), build(curin * 2 + 2, (curl + curr) / 2 + 1, curr);
  get<1>(seg[curin]) += get<1>(seg[curin * 2 + 1]) + get<1>(seg[curin * 2 + 2]);
  return;
}
void update(long long curin, long long curl, long long curr, long long ql, long long qr, long long val)
{
  lazyv(curin);
  if (qr < curl || curr < ql)
    return;
  if (ql <= curl && curr <= qr)
  {
    get<2>(seg[curin]) += val;
    lazyv(curin);
    return;
  }
  update(curin * 2 + 1, curl, (curl + curr) / 2, ql, qr, val), update(curin * 2 + 2, (curl + curr) / 2 + 1, curr, ql, qr, val);
  auto [minl, countl, lazyl] = seg[curin * 2 + 1];
  auto [minr, countr, lazyr] = seg[curin * 2 + 2];
  auto &[mincur, countcur, lazycoun] = seg[curin];
  if (minl < minr)
    mincur = minl, countcur = countl;
  else if (minl > minr)
    mincur = minr, countcur = countr;
  else if (minl == minr)
    mincur = minl, countcur = countl + countr;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long tests;
  cin >> tests;
  while (tests--)
  {
    long long trophies;
    cin >> trophies;
    long long height, length, hp, lp;
    cin >> height >> length >> hp >> lp;
    height -= (hp - 1), length -= (lp - 1);
    vector<tuple<long long, long long, long long, long long>> vti4(trophies); // toplx toply xlen->botrl ylen->botry
    for (auto &[a, b, c, d] : vti4)
    {
      cin >> a >> b >> c >> d;
      a -= (hp - 1), b -= (lp - 1);
      c += (hp - 1), d += (lp - 1);
      c = a + c - 1, d = b + d - 1;
      a = max(a, 0LL), b = max(b, 0LL), c = max(c, 0LL), d = max(d, 0LL);
      a = min(a, height - 1), b = min(b, length - 1), c = min(c, height - 1), d = min(d, length - 1);
    }
    map<long long, vector<tuple<long long, long long, long long>>> sweep; // xval l r val
    for (auto [a, b, c, d] : vti4)
    {
      sweep[a].emplace_back(b, d, 1);
      sweep[c + 1].emplace_back(b, d, -1);
    }
    seg.clear();
    seg.resize(length * 4, {0, 0, 0});
    build(0, 0, length - 1);
    long long ct = 0;
    auto it = sweep.begin();
    for (long long i = 0; i < height; i++)
    {
      if (it != sweep.end())
      {
        if (it->first == i)
        {
          for (auto [left, right, val] : it->second)
            update(0, 0, length - 1, left, right, val);
          it++;
        }
      }
      auto [minnum, countmin, _] = seg[0];
      if (minnum == 0)
        ct += countmin;
    }
    cout << ct << "\n";
  }
}