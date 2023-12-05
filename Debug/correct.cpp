#include <bits/stdc++.h>
using namespace std;
int maxi;
vector<vector<int>> adjlist;
vector<int> arr;
int dfs(int cur, int par)
{
    vector<int> vi(2, 0);
    for (auto a : adjlist[cur])
        if (a != par)
            vi.push_back(dfs(a, cur));
    sort(vi.begin(), vi.end(), greater<int>());
    maxi = max(maxi, vi[0] + vi[1] + arr[cur]);
    return vi[0] + arr[cur];
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("correctoutput.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    arr.resize(n);
    adjlist.resize(n);
    for (auto &a : arr)
        cin >> a;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adjlist[a - 1].push_back(b - 1), adjlist[b - 1].push_back(a - 1);
    }
    maxi = INT_MIN;
    dfs(0, -1);
    cout << maxi << '\n';
    for (int i = 0; i < m; i++)
    {
        int in, val;
        cin >> in >> val;
        arr[in - 1] = val;
        maxi = INT_MIN;
        dfs(0, -1);
        cout << maxi << "\n";
    }
}