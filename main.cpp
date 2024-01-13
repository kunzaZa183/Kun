#include <bits/stdc++.h>
using namespace std;
const int maxn = 200001;
vector<int> arr[maxn];
bitset<20> bs, used;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            arr[i].clear();
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            arr[a].push_back(b);
        }
        if (n >= 20)
        {
            cout << n << '\n';
            for (int i = 0; i < n; i++)
                cout << i + 1 << " ";
            cout << "\n";
        }
        else if (n < 20)
        {
            int targ = n / 5;
            for (int target = 1; target <= targ; target++)
            {
                vector<int> vi(n, 0);
                for (int i = 0; i < target; i++)
                    vi[i] = 1;
                sort(vi.begin(), vi.end());
                do
                {
                    bs.reset();
                    used.reset();
                    for (int i = 0; i < n; i++)
                        if (bs[i] != vi[i])
                        {
                            used[i] = 1;
                            for (int j = i; j < n; j += i + 1)
                                bs[j] = !bs[j];
                        }
                    vector<int> vi;
                    for (int i = 1; i <= n; i++)
                        for (auto a : arr[i])
                            if (used[i - 1] && !used[a - 1])
                                goto A;
                    for (int i = 0; i < n; i++)
                        if (used[i])
                            vi.push_back(i + 1);
                    cout << vi.size() << "\n";
                    for (auto a : vi)
                        cout << a << " ";
                    cout << '\n';
                    goto B;
                A:;
                } while (next_permutation(vi.begin(), vi.end()));
            }
            cout << "-1\n";
        B:;
        }
    }
}