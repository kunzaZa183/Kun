#include <iostream>

using namespace std;

typedef long long ll;

/**
 * Return the number of unique Jenga towers that can be built using N or fewer
 * bricks. Give your answer modulo 3359232.
 *
 * N: the maximum number of bricks to use
 */

const int MOD = 3359232;

ll logpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    ll x = logpow(a, b / 2);
    if (b % 2 == 1)
        return x * x % MOD * a % MOD;
    return x * x % MOD;
}

int solve(ll N)
{
    N /= 3;
    N++;
    int smth = logpow(2, N) - 2 + MOD;
    return smth % MOD;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        ll N;
        cin >> N;
        cout << solve(N) << '\n';
    }
}