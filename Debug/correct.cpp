#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) x.begin(), x.end()
#define pb push_back
#define sz(x) (int)x.size()
#define f first
#define s second
using namespace std;
const int N = 1e5 + 5;
vector<int> g[N];
int pr[N], sz[N], d[N][20], lv[N]{0};
bool vis[N]{0};
int getsize(int u, int p)
{
  sz[u] = 1;
  for (auto v : g[u])
  {
    if (v == p || vis[v])
      continue;
    sz[u] += getsize(v, u);
  }
  return sz[u];
}
int getct(int u, int p, int n)
{
  for (auto v : g[u])
  {
    if (vis[v] || v == p)
      continue;
    if (sz[v] * 2 > n)
      return getct(v, u, n);
  }
  return u;
}
void getd(int u, int p, int ct)
{
  for (auto v : g[u])
  {
    if (vis[v] || v == p)
      continue;
    d[v][lv[ct]] = d[u][lv[ct]] + 1;
    getd(v, u, ct);
  }
}
void play(int u = 1, int p = 0)
{
  int ct = getct(u, u, getsize(u, u));
  vis[ct] = 1;
  pr[ct] = p;
  lv[ct] = lv[p] + 1;
  for (auto v : g[ct])
  {
    if (vis[v])
      continue;
    d[v][lv[ct]] = 1;
    getd(v, ct, ct);
  }
  for (auto v : g[ct])
  {
    if (vis[v])
      continue;
    play(v, ct);
  }
}
vector<int> r[N], rp[N];
vector<int> fw[2][N];
void upd(int i, int j, int idx)
{
  if (i == 0)
    idx = upper_bound(all(r[j]), idx) - r[j].begin();
  else
    idx = upper_bound(all(rp[j]), idx) - rp[j].begin();
  for (; idx < sz(fw[i][j]); idx += idx & -idx)
    fw[i][j][idx]++;
}
int qr(int i, int j, int idx, int res = 0)
{
  if (i == 0)
    idx = upper_bound(all(r[j]), idx) - r[j].begin();
  else
    idx = upper_bound(all(rp[j]), idx) - rp[j].begin();
  for (; idx; idx -= idx & -idx)
    res += fw[i][j][idx];
  return res;
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("correctoutput.txt", "w", stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n - 1; i++)
  {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  play();
  vector<pair<int, pii>> qry;
  for (int i = 0; i < q; i++)
  {
    int t, u, k;
    cin >> t;
    if (t == 1)
    {
      cin >> u >> k;
      qry.pb({t, {u, k}});
      int v = u;
      int cur = 0;
      while (1)
      {
        r[v].pb(k - cur);
        if (pr[v] == 0)
          break;
        cur = d[u][lv[pr[v]]];
        rp[v].pb(k - cur);
        v = pr[v];
      }
    }
    else
    {
      int u;
      cin >> u;
      qry.pb({t, {u, 0}});
    }
  }
  for (int i = 1; i <= n; i++)
  {
    sort(all(r[i]));
    sort(all(rp[i]));
    r[i].erase(unique(all(r[i])), r[i].end());
    rp[i].erase(unique(all(rp[i])), rp[i].end());
    fw[0][i].resize(r[i].size() + 1);
    fw[1][i].resize(rp[i].size() + 1);
  }
  for (auto it : qry)
  {
    if (it.f == 1)
    {
      int cur = 0;
      int u, v;
      u = v = it.s.f;
      int k = it.s.s;
      while (1)
      {
        upd(0, v, k - cur);
        if (pr[v] == 0)
          break;
        cur = d[u][lv[pr[v]]];
        upd(1, v, k - cur);
        v = pr[v];
      }
    }
    if (it.f == 2)
    {
      int cur = 0;
      int u, v;
      u = v = it.s.f;
      int ans = 0;
      while (1)
      {
        ans += qr(0, v, 1e9) - qr(0, v, cur - 1);
        if (pr[v] == 0)
          break;
        cur = d[u][lv[pr[v]]];
        ans -= qr(0, v, 1e9) - qr(1, v, cur - 1);
        v = pr[v];
      }
      cout << ans << "\n";
    }
  }
}