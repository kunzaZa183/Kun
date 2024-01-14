#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 200000, MOD = 998244353;
int arr[maxn];
int fact[maxn + 1], invfact[maxn + 1], prefin[maxn + 1], sufin[maxn + 2];
int logpow(int a, int b)
{
    if (b == 1)
        return a;
    if (b == 0)
        return 1;
    int x = logpow(a, b / 2);
    if (b % 2 == 0)
        return x * x % MOD;
    return x * x % MOD * a % MOD;
}
int choose(int a, int b)
{
    if (a < b)
        return 0;
    return fact[a] * invfact[b] % MOD * invfact[a - b] % MOD;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tests;
    cin >> tests;
    fact[0] = 1;
    prefin[0] = 1;
    for (int i = 1; i <= maxn; i++)
    {
        fact[i] = fact[i - 1] * i % MOD;
        prefin[i] = prefin[i - 1] * fact[i] % MOD;
    }
    sufin[maxn + 1] = 1;
    for (int i = maxn; i >= 1; i--)
        sufin[i] = sufin[i + 1] * fact[i] % MOD;
    int all = logpow(prefin[maxn], MOD - 2);
    invfact[0] = 1;
    for (int i = 1; i <= maxn; i++)
        invfact[i] = prefin[i - 1] * sufin[i + 1] % MOD * all % MOD;
    while (tests--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int maxi = 0;
        int lastsquare = -1, numuse = 0;
        int ways;
        for (int i = 0; i < n; i++)
            if (arr[i] != -1)
            {
                if (arr[i] < maxi)
                {
                    cout << "0\n";
                    goto END;
                }
                maxi = arr[i];
            }
        if (arr[n - 1] != n && arr[n - 1] != -1)
        {
            cout << "0\n";
            continue;
        }
        arr[n - 1] = n;
        for (int i = 0; i < n; i++)
            if (arr[i] != -1)
            {
                if (lastsquare == -1)
                {
                    ways = choose(i + 1, arr[i]) * choose(i + 1, arr[i]) % MOD * fact[arr[i]] % MOD;
                    lastsquare = i;
                    numuse = arr[i];
                }
                else
                {
                    int ct = 0;
                    for (int j = 0; j <= arr[i] - numuse; j++)
                    {
                        int firstval = choose(i - lastsquare, j) * choose(lastsquare + 1 - numuse, j) % MOD * fact[j] % MOD;
                        int secondval = choose(i + 1 - numuse - j, arr[i] - numuse - j) * choose(i - lastsquare, arr[i] - numuse - j) % MOD * fact[arr[i] - numuse - j] % MOD;
                        ct += firstval * secondval % MOD;
                        ct %= MOD;
                    }
                    ways *= ct;
                    ways %= MOD;
                    lastsquare = i;
                    numuse = arr[i];
                }
            }
        cout << ways << '\n';
    END:;
    }
}