#include <bits/stdc++.h>
using namespace std;
map<string, pair<string, string>> mspss;
int main()
{
    string order;
    cin >> order;
    string name1, equal, first, last;
    while (cin >> name1 >> equal >> first >> last, name1 != "-1")
        mspss[name1] = { first.substr(1, 3), last.substr(0, 3) };
    vector<string> cur;
    for (auto a : mspss)
        if (a.first.back() == 'A')
            cur.push_back(a.first);
    vector<int> vi;
    for (auto a : cur)
    {
        int in = 0, ct = 0;
        while (a.back() != 'Z')
        {
            if (in == order.size())
                in = 0;
            if (order[in] == 'L')
                a = mspss[a].first;
            else if (order[in] == 'R')
                a = mspss[a].second;
            in++;
            ct++;
        }
        vi.push_back(ct);
    }
    for (auto a : vi)
        cout << a << '\n';
}