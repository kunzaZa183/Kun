#include <bits/stdc++.h>
#include <set>
#include <unordered_set>
using namespace std;
int arr[6], all[36], eachval[6], diff[6];
bitset<36> add;
multiset<int> msi;
void solve()
{
    for (int i = 0; i < 36; i++)
        cin >> all[i];
    for (int i = 1; i < 6; i++)
        arr[i] = i;
    for (arr[2] = 2; arr[2] <= 12; arr[2]++)
        for (arr[3] = arr[2] + 1; arr[3] <= 18; arr[3]++)
            for (arr[4] = arr[3] + 1; arr[4] <= 24; arr[4]++)
                for (arr[5] = arr[4] + 1; arr[5] <= 30; arr[5]++)
                {
                    msi.clear();
                    int ct = 1;
                    add.set();
                    for (int i = 0; i < 6; i++)
                        add[arr[i]] = 0;
                    for (int i = 0; i < 36; i++)
                        if (add[i])
                            msi.insert(all[i]);
                    eachval[0] = all[0];
                    for (int i = 1; i < 6; i++)
                        diff[i] = all[arr[i]] - all[arr[0]];
                    while (!msi.empty())
                    {
                        eachval[ct] = *msi.begin();
                        msi.erase(msi.begin());
                        for (int i = 1; i < 6; i++)
                        {
                            auto it = msi.find(eachval[ct] + diff[i]);
                            if (it != msi.end())
                                msi.erase(it);
                            else
                                goto A;
                        }
                        ct++;
                    }
                    cout << 0;
                    for (int i = 1; i < 6; i++)
                        cout << " " << all[arr[i]] - all[arr[0]];
                    cout << "\n";
                    cout << all[0];
                    for (int i = 1; i < 6; i++)
                        cout << ' ' << eachval[i] - eachval[0] + all[0];
                    cout << "\n";
                    return;
                A:;
                }
    cout << "IMPOSSIBLE\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--)
        solve();
}