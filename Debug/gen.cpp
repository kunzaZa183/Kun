#include <bits/stdc++.h>
using namespace std;
int main(int a, int b)
{
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    srand(time(NULL));
    cout << "4 ";
    cout << rand() % 16 << ' ' << rand() % 16 << " " << rand() % 16 << ' ' << rand() % 16 << '\n';
}