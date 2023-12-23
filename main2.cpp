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
        for (int i = 0; i < n; i++)
            if (arr[i] == k)
            {
                cout << "-1\n";
                goto B;
            }
        for (int i = 0; i < n; i++)
            if (arr[0] > k != arr[i] > k)
            {
                cout << "-1\n";
                goto B;
            }
        goto C;
    B:
        continue;
    C:
        if (arr[0] > k)
        {
            int firstgcd = arr[0] - k;
            for (int i = 1; i < n; i++)
                firstgcd = gcd(firstgcd, arr[i] - k);
            firstgcd += k;
            int sum = 0;
            for (int i = 0; i < n; i++)
                sum += (arr[i] - firstgcd) / (firstgcd - k);
            cout << sum << '\n';
        }
        else if (arr[0] < k)
        {
            int firstgcd = k - arr[0];
            for (int i = 1; i < n; i++)
                firstgcd = gcd(firstgcd, k-arr[i]);
            firstgcd = k - firstgcd;
            int sum = 0;
            for (int i = 0; i < n; i++)
                sum += (firstgcd - arr[i]) / (k - firstgcd);
            cout << sum << '\n';
        }
    }
}