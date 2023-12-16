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
int small2pow(int num)
{
    int cur = 1;
    while (cur <= num)
        cur *= 2;
    return cur / 2;
}
int floorlog2(int num)
{
    int ct = 0;
    while (num != 1)
    {
        ct++;
        num /= 2;
    }
    return ct;
}
vector<pair<int, int>> vpii;
int recur(int curnum, int allchild)
{
    if (small2pow(allchild) == allchild)
    {
        int tmp = floorlog2(allchild);
        return (curnum * vpii[tmp].first % MOD + vpii[tmp].second) % MOD;
    }
    int lessthan = small2pow(allchild);
    int leftchild = lessthan, rightchild = allchild - leftchild;
    if (rightchild < lessthan / 2)
    {
        rightchild = lessthan / 2;
        leftchild = allchild - rightchild;
    }

    int retval = ((recur(curnum * 2, leftchild) + recur(curnum * 2 + 1, rightchild)) % MOD);
    int someval = (logpow(2, allchild) - 1) - (logpow(2, leftchild) - 1) - (logpow(2, rightchild) - 1);
    while (someval < 0)
        someval += MOD;
    someval %= MOD;
    retval += curnum * someval % MOD;
    retval %= MOD;
    return retval;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tests;
    cin >> tests;
    vpii.emplace_back(1, 0);
    int tmp = 1;
    for (int i = 1; i <= 62; i++)
    {
        tmp *= 2;
        int tmpmod = tmp / 2 % MOD;
        pair<int, int> pii;

        // left
        pii.first += vpii.back().first * 2 % MOD;
        pii.second += vpii.back().second;
        pii.first %= MOD, pii.second %= MOD;

        // right
        pii.first += vpii.back().first * 2 % MOD;
        pii.second += vpii.back().second + vpii.back().first;
        pii.first %= MOD, pii.second %= MOD;

        // center
        pii.first += (logpow(2, tmp % MOD) - 1) - (logpow(2, tmpmod) - 1) * 2 % MOD;
        while (pii.first < 0)
            pii.first += MOD;
        pii.first %= MOD;

        vpii.push_back(pii);
    }
    while (tests--)
    {
        int n;
        cin >> n;
        cout << recur(1, n) << '\n';
    }
}