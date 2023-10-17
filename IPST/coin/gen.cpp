#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(time(NULL));
    freopen("in.txt", "w", stdout);
    int n = 20, q = 10, tape = rand() % 5;
    cout << n << ' ' << q << " " << tape << "\n";
    const int smallnum = 5;
    for (int i = 0; i < n; i++)
        cout << rand() % smallnum << ' ';
    cout << "\n";
    for (int i = 0; i < q; i++)
        cout << rand() % n << " " << rand() % smallnum << ' ' << rand() % smallnum << "\n";
}