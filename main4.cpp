#include <bits/stdc++.h>
using namespace std;
#define int long long
struct type
{
    bool legit;
    int start;
    int len;
    type(const bool a, const int c, const int b)
    {
        legit = a, start = c, len = b;
    }
};
string s;
const int maxn = 1000000;
int maxr[maxn], maxl[maxn];
vector<type> vt;
map<int, vector<int>> available;  // size start index
map<int, vector<int>> available2; // size index
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int len;
    cin >> len;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        maxr[i] = len - 1, maxl[i] = 0;
    vt.emplace_back(s[0] == 'T', 0, 1);
    for (int i = 1; i < len; i++)
        if (s[i] == 'T')
        {
            if (vt.back().legit)
                vt.back().len++;
            else if (!vt.back().legit)
                vt.emplace_back(1, i, 1);
        }
        else if (s[i] == 'F')
        {
            if (vt.back().legit)
                vt.emplace_back(0, i, 1);
            else if (!vt.back().legit)
                vt.back().len++;
        }

    long long ans = 0;
    int forgot = 0;
    for (auto a : vt)
    {
        if (a.legit)
        {
            while (!available.empty())
            {
                if (available.begin()->first < a.len)
                    for (auto b : available.begin()->second)
                        ans += (a.start - b + 1) * available.begin()->first;
                else
                    break;
                available.erase(available.begin());
            }
            for (int i = 1; i < a.len; i++)
                available[i].push_back(a.start + a.len - i);

            while (!available2.empty())
            {
                if (available2.begin()->first < a.len)
                    for (auto b : available2.begin()->second)
                        maxr[b] = a.start + available2.begin()->first - 1;
                else
                    break;
                available2.erase(available2.begin());
            }
            available2[a.len].push_back(forgot);
        }
        forgot++;
    }

    for (auto &a : available)
        for (auto b : a.second)
            ans += (len - (b + a.first - 1)) * a.first;

    available.clear();
    available2.clear();

    for (int i = vt.size() - 1; i >= 0; i--)
        if (vt[i].legit)
        {
            while (!available.empty())
            {
                if (available.begin()->first <= vt[i].len)
                    for (auto a : available.begin()->second)
						ans += (a - (vt[i].start + vt[i].len - available.begin()->first)) * available.begin()->first;
                else
                    break;
                available.erase(available.begin());
            }
            for (int j = 1; j < vt[i].len; j++)
                available[j].push_back(vt[i].start);

            while (!available2.empty())
            {
                if (available2.begin()->first <= vt[i].len)
                    for (auto b : available2.begin()->second)
                        maxl[b] = vt[i].start + vt[i].len - available2.begin()->first + 1;
                else
                    break;
                available2.erase(available2.begin());
            }
            available2[vt[i].len].push_back(i);
        }

    for (auto &a : available)
        for (auto b : a.second)
            ans += (b + 1) * a.first;

    for (int i = 0; i < vt.size(); i++)
        if (vt[i].legit)
        {
            ans += (vt[i].start - maxl[i] + 1) * (maxr[i] - (vt[i].start + vt[i].len - 1) + 1) * vt[i].len;
            for (int j = 1; j <= vt[i].len - 2; j++)
                ans += j * (vt[i].len - 2 - j + 1);
        }
    cout << ans << "\n";
}
