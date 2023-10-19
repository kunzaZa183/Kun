#include <bits/stdc++.h>
using namespace std;
const int maxn = 2500, maxm = 2500, x = 0;
int arr1[maxn] = {}, arr2[maxm] = {};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    for (int i = 0; i < m; i++)
        cin >> arr2[i];
    vector<int> move1, move2;
    for (int i = 0; i < n; i++)
    {
        int x = arr1[i], y = i + 1;
        if (x == y)
            continue;
        int in1 = find(arr1, arr1 + n, x) - arr1, in2 = find(arr1, arr1 + n, y) - arr1;
        if (in1 > in2)
            swap(in1, in2);
        int a = in1, b = in2 - in1 - 1, c = n - in2 - 1;
        move1.push_back(a + 1);
        move1.push_back(b + 1);
        move1.push_back(c + 1);
        swap(arr1[in1], arr1[in2]);
    }
    for (int i = 0; i < m; i++)
    {
        int x = arr2[i], y = i + 1;
        if (x == y)
            continue;
        int in1 = find(arr2, arr2 + m, x) - arr2, in2 = find(arr2, arr2 + m, y) - arr2;
        if (in1 > in2)
            swap(in1, in2);
        int a = in1, b = in2 - in1 - 1, c = m - in2 - 1;
        move2.push_back(a + 1);
        move2.push_back(b + 1);
        move2.push_back(c + 1);
        swap(arr2[in1], arr2[in2]);
    }
    if (move1.size() % 2 != move2.size() % 2)
    {
        if (n % 2 == 1)
            for (int i = 0; i < n; i++)
                move1.push_back(1);
        else if (m % 2 == 1)
            for (int i = 0; i < m; i++)
                move2.push_back(1);
        else
        {
            cout << "-1\n";
            return 0;
        }
    }
    while (move1.size() < move2.size())
    {
        move1.push_back(1);
        move1.push_back(n);
    }
    while (move1.size() > move2.size())
    {
        move2.push_back(1);
        move2.push_back(m);
    }
    cout << move1.size() << "\n";
    for (int i = 0; i < move1.size(); i++)
        cout << move1[i] << " " << move2[i] << "\n";
}