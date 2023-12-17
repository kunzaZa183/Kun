#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;
int logpow(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    int x = logpow(a, b / 2);
    if (b % 2 == 1)
        return x * x % MOD * a % MOD;
    return x * x % MOD;
}
map<int, pair<int, int>> vpii;
int recur(int curnum, int allchild)
{
    curnum %= MOD;
    auto it = vpii.find(allchild);
    if (it != vpii.end())
        return (curnum * it->second.first % MOD + it->second.second) % MOD;

    int leftchild = allchild - allchild / 2, rightchild = allchild / 2;

    int retval = ((recur(curnum * 2, leftchild) + recur(curnum * 2 + 1, rightchild)) % MOD);
    int someval = (logpow(2, allchild) - 1) - (logpow(2, leftchild) - 1) - (logpow(2, rightchild) - 1);
    while (someval < 0)
        someval += MOD;
    someval %= MOD;
    retval += curnum * someval % MOD;
    retval %= MOD;

    auto itl = vpii.find(leftchild), itr = vpii.find(rightchild);
    pair<int, int> pii;

    // left
    pii.first += itl->second.first * 2 % MOD;
    pii.second += itl->second.second;
    pii.first %= MOD, pii.second %= MOD;

    // right
    pii.first += itr->second.first * 2 % MOD;
    pii.second += itr->second.second + itr->second.first;
    pii.first %= MOD, pii.second %= MOD;

    // center
    pii.first += (logpow(2, allchild) - 1) - (logpow(2, leftchild) - 1) - (logpow(2, rightchild) - 1);
    while (pii.first < 0)
        pii.first += MOD;
    pii.first %= MOD;

    vpii[allchild] = pii;

    return retval;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tests;
    cin >> tests;
    vpii[1] = {1, 0};
    while (tests--)
    {
        int n;
        cin >> n;
        cout << recur(1, n) << '\n';
    }
}