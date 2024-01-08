#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000;
int arr[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    multiset<int> msi;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        msi.insert(tmp);
    }
    int ct = 0;
    while (!msi.empty())
    {
        auto it = msi.begin();
        auto target = msi.upper_bound(x - *it);
        if (target != msi.begin())
        {
            target--;
            if (target != msi.begin())
                msi.erase(target);
        }
        msi.erase(msi.begin());
        ct++;
    }
    cout << ct << "\n";
}