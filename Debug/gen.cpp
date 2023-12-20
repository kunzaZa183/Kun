#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "w", stdout);
    srand(time(NULL));
    const int seeds = 5;
    for (int i = 0; i < seeds; i++)
        cout << rand() % 30 << ' ' << rand() % 10 + 1 << "\n";
    cout << "-1 -1\n";
    for (int i = 0; i < 7; i++)
    {
        int ranges = 4;
        vector<tuple<int, int, int>> vpii;
        vpii.emplace_back(rand() % 20, rand() % 5, rand() % 5 + 1);
        for (int i = 0; i < ranges - 1; i++)
        {
            auto [last1, last2, last3] = vpii.back();
            vpii.emplace_back(rand() % 30, last2 + last3 + rand() % 10, rand() % 5 + 1);
        }
        for (auto [a, b, c] : vpii)
            cout << a << ' ' << b << ' ' << c << "\n";
        cout << "-1 -1 -1\n";
    }
}