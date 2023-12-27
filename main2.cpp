#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> vi, vi2;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int num, x;
    cin >> num >> x;
    vector<int> arr(num);
    for (auto& a : arr)
        cin >> a;
    int f = num / 2;
    int l = num - f;
    for (int i = 0; i < (1 << f); i++)
    {
        int sum = 0;
        for (int j = 0; j < f; j++)
            if (i & (1 << j))
            {
                sum += arr[j];
                if (sum > x)
                    goto B;
            }
        vi.push_back(sum);
    B:;
    }
    for (int i = 0; i < (1 << l); i++)
    {
        int sum = 0;
        for (int j = 0; j < l; j++)
            if (i & (1 << j))
            {
                sum += arr[f + j];
                if (sum > x)
                    goto A;
            }
        vi2.push_back(sum);
    A:;
    }
    sort(vi.begin(), vi.end());
    sort(vi2.begin(), vi2.end(), greater<int>());
    vector<pair<int, int>> vpii1, vpii2;
    for (auto a : vi)
        if (vpii1.empty())
            vpii1.emplace_back(a, 1);
        else if (vpii1.back().first == a)
            vpii1.back().second++;
        else
            vpii1.emplace_back(a, 1);

    for (auto a : vi2)
        if (vpii2.empty())
            vpii2.emplace_back(a, 1);
        else if (vpii2.back().first == a)
            vpii2.back().second++;
        else
            vpii2.emplace_back(a, 1);

    int pt1 = 0, pt2 = 0;
    int res = 0;
    while (pt1 < vpii1.size() && pt2 < vpii2.size())
    {
        if (vpii1[pt1].first + vpii2[pt2].first == x)
        {
            res += vpii1[pt1].second * vpii2[pt2].second;
            pt2++;
        }
        else if (vpii1[pt1].first + vpii2[pt2].first > x)
            pt2++;
        else
            pt1++;
    }
    cout << res << "\n";
}