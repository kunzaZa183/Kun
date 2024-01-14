#include <bits/stdc++.h>
using namespace std;
#define int long long
struct kun
{
    int bef, rep;
    vector<int> newnum;
    friend bool operator<(kun a, kun b)
    {
        return a.bef < b.bef;
    }
};
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--)
    {
        int n, q;
        cin >> n >> q;
        vector<kun> vpivii;
        int lastc = 0;
        kun tmp;
        tmp.bef = 0;
        tmp.rep = 1;
        vpivii.push_back(tmp);
        for (int i = 0; i < n; i++)
        {
            int tp, x;
            cin >> tp >> x;
            if (tp == 1)
                vpivii.back().newnum.push_back(x);
            else
            {
                vpivii.back().rep = x + 1;
                kun tmp;
                if (vpivii.back().bef == LLONG_MAX)
                    tmp.bef = LLONG_MAX;
                else if (log10(vpivii.back().bef + vpivii.back().newnum.size()) + log10(vpivii.back().rep) > 18.3)
                    tmp.bef = LLONG_MAX;
                else
                    tmp.bef = (vpivii.back().bef + vpivii.back().newnum.size()) * vpivii.back().rep;
                tmp.rep = 1;
                vpivii.push_back(tmp);
            }
        }
        while (vpivii.back().bef == LLONG_MAX)
            vpivii.pop_back();
        for (int i = 0; i < q; i++)
        {
            int query;
            cin >> query;
            query--;
            for (int i = vpivii.size() - 1; i >= 0; i--)
            {
                query %= vpivii[i].bef + vpivii[i].newnum.size();
                if (query >= vpivii[i].bef)
                {
                    cout << vpivii[i].newnum[query - vpivii[i].bef] << ' ';
                    break;
                }
            }
        }
        cout << '\n';
    }
}