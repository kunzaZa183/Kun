#include <bits/stdc++.h>
using namespace std;
const int maxn = 100001;
int canmod[maxn];
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
        long long ans = 0;
        for (int i = 1; i <= n; i++)
            canmod[m % i]++;
        for (int i = 1; i <= n; i++)
        {
            canmod[m % i]--;
            for (int j = m % i; j <= n; j += i)
                ans += canmod[j];
        }
        cout << ans << "\n";
    }
}