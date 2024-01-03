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
        int n, qs;
        cin >> n >> qs;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int sum = accumulate(arr, arr + n, 0LL);
        int actualsum = sum;
        int mini = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            if (mini > arr[i])
            {
                sum -= arr[i];
                mini -= arr[i];
                mini = min(mini, arr[i]);
            }
            else
            {
                sum -= mini;
                mini = 0;
                break;
            }
        }
        cout << sum << "\n";
        while (qs--)
        {
            int in, val;
            cin >> in >> val;
            in--;
            actualsum += val - arr[in];
            arr[in] = val;
            sum = actualsum;
            mini = arr[n - 1];
            for (int i = n - 2; i >= 0; i--)
            {
                if (mini > arr[i])
                {
                    sum -= arr[i];
                    mini -= arr[i];
                    mini = min(mini, arr[i]);
                }
                else
                {
                    sum -= mini;
                    mini = 0;
                    break;
                }
            }
            cout << sum << "\n";
        }
    }
}