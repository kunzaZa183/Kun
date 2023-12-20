#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("in.txt", "w", stdout);
    srand(time(NULL));
    int n = 10, k = 5 + rand() % (n - 5);
    vector<int> allnum;
    for (int i = 1; i <= n; i++)
        allnum.push_back(i);
    vector<int> allnum2 = allnum;
    vector<int> vi, vi2;
    for (int i = 0; i < k; i++)
    {
        int x = rand() % allnum.size(), y = rand() % allnum2.size();
        vi.push_back(allnum[x]), vi2.push_back(allnum2[y]);
        allnum.erase(allnum.begin() + x), allnum2.erase(allnum2.begin() + y);
    }
    cout << n << ' ' << k << '\n';
    for (auto a : vi)
        cout << a << ' ';
    cout << '\n';
    for (auto a : vi2)
        cout << a << ' ';
    cout << "\n";
}