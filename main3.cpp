#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 200000;
int arr[maxn];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = 0; i < n; i++)
            if (arr[i] != arr[0])
                goto A;
        cout << "0\n";
        continue;
    A:
        if (arr[0] == k)
        {
            cout << "X-1\n";
            continue;
        }
        for (int i = 0; i < n; i++)
            if (arr[0] > k != arr[i] > k)
            {
                cout << i << ' ' << int32_t(arr[0] > k) << ' ' << int32_t(arr[i] > k) << '\n';
                cout << "-1\n";
                goto B;
            }
        goto C;
    B:
        continue;
    C:
        int firstgcd = arr[0] - k;
        for (int i = 1; i < n; i++)
            firstgcd = __gcd(firstgcd, arr[i] - k);
        firstgcd += k;
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += (arr[i] - firstgcd) / (firstgcd - k);
        cout << sum << '\n';
    }
}