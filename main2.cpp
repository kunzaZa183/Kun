#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 200000, root = 0;
int arr[maxn], parent[maxn], origarr[maxn];
vector<int> adjlist[maxn];
vector<pair<int, int>> give[maxn]; // how much, to who
int sum = 0;
struct message
{
    int from, to, siz;
    message(int a, int b, int c)
    {
        from = a, to = b, siz = c;
    }
};
queue<message> qm;
vector<message> vm;
void dfs(int cur, int par)
{
    parent[cur] = par;
    for (auto a : adjlist[cur])
        if (a != par)
            dfs(a, cur);
    if (arr[cur] < sum)
    {
        arr[par] -= sum - arr[cur];
        give[par].emplace_back(sum - arr[cur], cur);
        arr[cur] = sum;
    }
    else if (arr[cur] > sum)
    {
        arr[par] += arr[cur] - sum;
        give[cur].emplace_back(arr[cur] - sum, par);
        arr[cur] = sum;
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        origarr[i] = arr[i];
        sum += arr[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adjlist[a].push_back(b), adjlist[b].push_back(a);
    }
    sum /= n;
    dfs(root, root);
    for (int i = 0; i < n; i++)
        sort(give[i].begin(), give[i].end(), greater<pair<int, int>>());
    for (int i = 0; i < n; i++)
        if (!give[i].empty())
            if (give[i].back().first <= origarr[i])
                qm.emplace(i, give[i].back().second, give[i].back().first);
    while (!qm.empty())
    {
        message tmp = qm.front();
        qm.pop();
        if (!give[tmp.from].empty())
            if (give[tmp.from].back() == make_pair(tmp.siz, tmp.to))
            {
                vm.push_back(tmp);
                origarr[tmp.from] -= tmp.siz;
                origarr[tmp.to] += tmp.siz;
                give[tmp.from].pop_back();
                if (!give[tmp.from].empty())
                {
                    if (give[tmp.from].back().first <= origarr[tmp.from])
                        qm.emplace(tmp.from, give[tmp.from].back().second, give[tmp.from].back().first);
                }
                if (!give[tmp.to].empty())
                {
                    if (give[tmp.to].back().first <= origarr[tmp.to])
                        qm.emplace(tmp.to, give[tmp.to].back().second, give[tmp.to].back().first);
                }
            }
    }
    cout << vm.size() << "\n";
    for (auto a : vm)
        cout << a.from + 1 << ' ' << a.to + 1 << ' ' << a.siz << "\n";
}