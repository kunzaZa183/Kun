#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 250000;
int arr[maxn];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    int minx = INT_MIN;
    for (int i = 0; i < n; i++)
        minx = max(minx, arr[i] - i);
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    int maxadd = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        maxadd = max(maxadd, minx + i - arr[i]);
        ans += minx + i - arr[i];
    }

    int l = 0, r = 1e13;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (maxadd + mid <= (ans + mid * n) / m)
            r = mid;
        else
            l = mid + 1;
    }
    ans += l * n;
    for (int i = 0; i < m; i++)
        if (ans % m == 0)
            break;
        else
            ans += n;
    if (ans % m != 0)
        cout << "-1\n";
    else
        cout << ans / m << '\n';
}