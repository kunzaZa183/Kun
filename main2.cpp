#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1000000;
int arr[maxn];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int sum = 0, maxi = 0;
        vector<pair<int, int>> vpii;
        for (int i = 0; i < n; i++)
            if (vpii.empty())
                vpii.emplace_back(1, arr[i]);
            else if (arr[i] > vpii.back().second)
                vpii.emplace_back(1, arr[i]);
            else
            {
                int ct = 1;
                while (!vpii.empty())
                {
                    if (arr[i] > vpii.back().second)
                    {
                        vpii.emplace_back(ct, arr[i]);
                        break;
                    }
                    else
                    {
                        ct += vpii.back().first;
                        vpii.pop_back();
                    }
                }
                if (vpii.empty())
                    vpii.emplace_back(ct, arr[i]);
            }
        for (auto a : vpii)
            sum += a.first * a.second;
        maxi = sum;
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] > vpii.back().second)
            {
                vpii.emplace_back(1, arr[i]);
                sum += arr[i];
            }
            else
            {
                int ct = 1;
                while (!vpii.empty())
                {
                    if (arr[i] > vpii.back().second)
                    {
                        vpii.emplace_back(ct, arr[i]);
                        sum += ct * arr[i];
                        break;
                    }
                    else
                    {
                        ct += vpii.back().first;
                        sum -= vpii.back().first * vpii.back().second;
                        vpii.pop_back();
                    }
                }
                if (vpii.empty())
                {
                    vpii.emplace_back(ct, arr[i]);
                    sum += ct * arr[i];
                }
            }
            maxi = max(maxi, sum);
        }
        cout << maxi + n << '\n';
    }
}