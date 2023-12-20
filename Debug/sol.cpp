#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    vector<pair<int, int>> allseeds;
    int num = 0, range;
    cin >> num >> range;
    while (num != -1)
    {
        allseeds.emplace_back(num, num + range);
        cin >> num >> range;
    }
    sort(allseeds.begin(), allseeds.end());
    for (int i = 0; i < 7; i++)
    {
        vector<tuple<int, int, int>> vtiii;
        int a = 0, b = 0, c = 0;
        while (cin >> a >> b >> c, a != -1)
            vtiii.emplace_back(b, b + c, a);
        sort(vtiii.begin(), vtiii.end());
        vector<pair<int, int>> last;
        for (auto &a : allseeds)
        {
            for (auto [source, end, dest] : vtiii)
                if (source >= a.second)
                    break;
                else if (source >= a.first)
                {
                    if (end >= a.second)
                    {
                        last.emplace_back(dest, dest + a.second - source);
                        a.second = source;
                        break;
                    }
                    else if (end > a.first)
                    {
                        last.emplace_back(a.first, source);
                        last.emplace_back(dest, dest + end - source);
                        a.first = end;
                    }
                }
                else if (source < a.first)
                {
                    if (end >= a.second)
                    {
                        last.emplace_back(dest + a.first - source, dest + a.second - source);
                        a.first = a.second;
                        break;
                    }
                    else if (end > a.first)
                    {
                        last.emplace_back(a.first - source + dest,dest + end - source);
                        a.first = end;
                    }
                }
            if (a.first != a.second)
                last.push_back(a);
        }
        sort(last.begin(), last.end());
        allseeds.swap(last);
        cout << allseeds.front().first << '\n';
    }
}