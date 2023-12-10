#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "w", stdout);
    srand(time(NULL));
    const int n = 80000, qs = 0;
    cout << n << ' ' << qs << "\n";
    int par[n];
    for (int i = 1; i < n; i++)
        par[i] = i - 1;
    for (int i = 0; i < n; i++)
        cout << rand() % 1000 - 500 << ' ';
    cout << "\n";
    for (int i = 1; i < n; i++)
        cout << i + 1 << ' ' << par[i] + 1 << '\n';
    for (int i = 0; i < qs; i++)
        cout << rand() % n + 1 << ' ' << rand() % 1000 - 500 << '\n';
}