#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "w", stdout);
    srand(time(NULL));
    int n = 6;
    const string s = "ACGT?";
    for (int i = 0; i < n; i++)
        cout << s[rand() % 5];
    cout << "\n";
}