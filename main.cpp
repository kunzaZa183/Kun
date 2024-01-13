#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000;
int dsu[maxn];
int find(int cur)
{
    if (dsu[cur] == cur)
        return cur;
    dsu[cur] = find(cur);
    return dsu[cur];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            dsu[i] = i;
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            dsu[find(a)] = find(b);
        }
        if (n >= 20)
        {
               
        }
    }
}