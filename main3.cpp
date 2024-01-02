#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    for (int i = 1; i < 1000; i++)
        s += to_string(i);
    cout << s[132] << s[133] << s[134];
}