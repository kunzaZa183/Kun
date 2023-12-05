#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "w", stdout);
    srand(time(NULL));
    const int n = 100000, qs = 100000;
    cout << n << ' ' << qs << "\n";
    int par[n];
    for (int i = 1; i < n; i++)
        par[i] = rand() % i;
    for (int i = 0; i < n; i++)
        cout << rand() % 1000 << ' ';
    cout << "\n";
    for (int i = 1; i < n; i++)
        cout << i + 1 << ' ' << par[i] + 1 << '\n';
    for (int i = 0; i < qs; i++)
        cout << rand() % n + 1 << ' ' << rand() % 1000 << '\n';
}