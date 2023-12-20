#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int time, dist;
    cin >> time >> dist;
    int ct = 0;
    for (int i = 0; i < time; i++)
        if (i * (time - i) > dist)
            ct++;
    cout << ct << "\n";
}