#include <bits/stdc++.h>
using namespace std;
const int maxn = (1 << 16);
bitset<maxn> bs;
void move(int length, int cur, int to, int canplace)
{
    if (length == 1)
    {
        cout << cur << " " << to << "\n";
        return;
    }
    move(length - 1, cur, canplace, to);
    cout << cur << " " << to << '\n';
    move(length - 1, canplace, to, cur);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cout << (1 << n) - 1 << "\n";
    move(n, 1, 3, 2);
}