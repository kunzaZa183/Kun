#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000
int rand1()
{
    int binary = rand();
    if (binary % 2)
        return rand() % MOD;
    else
        return -(rand() % MOD);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "w", stdout);
    int n = 100000, qs = 50000;
    srand(time(NULL));
    cout << n << ' ' << qs << '\n';
    for (int i = 0; i < n; i++)
        cout << rand1() << "\n";
    for (int i = 0; i < qs; i++)
    {
        int a = rand() % n + 1, b = rand() % n + 1;
        cout << min(a, b) << ' ' << max(a, b) << ' ' << rand1() + double(rand()) / RAND_MAX << '\n';
    }
}