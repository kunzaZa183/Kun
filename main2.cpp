#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    map<char, int> mci;
    for (auto a : s)
        mci[a]++;
    int ct = 0;
    for (auto a : mci)
        if (a.second % 2 == 1)
            ct++;
    if (ct > 1)
    {
        cout << "NO SOLUTION\n";
        return 0;
    }

    if (ct == 0)
    {
        string s1;
        for (auto a : mci)
            for (int i = 0; i < a.second / 2; i++)
                s1.push_back(a.first);
        cout << s1;
        reverse(s1.begin(), s1.end());
        cout << s1 << '\n';
    }
    else if (ct == 1)
    {
        pair<char, int> odd;
        for (auto a : mci)
            if (a.second % 2 == 1)
                odd = a;
        string s1;
        for (auto a : mci)
            if (a.second % 2 == 0)
                for (int i = 0; i < a.second / 2; i++)
                    s1.push_back(a.first);
        cout << s1;
        while (odd.second--)
            cout << odd.first;
        reverse(s1.begin(), s1.end());
        cout << s1 << '\n';
    }
}