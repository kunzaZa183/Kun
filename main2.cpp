#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 200000;
int arr[maxn];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
        cin >> arr[i];
    int moves = 0;
    for (int i = 1; i < num; i++)
        if (arr[i] < arr[i - 1])
        {
            moves += arr[i - 1] - arr[i];
            arr[i] = arr[i - 1];
        }
    cout << moves << "\n";
}