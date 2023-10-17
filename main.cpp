#include <bits/stdc++.h>
using namespace std;
#define int long long
int arr[500000];
int seg[2000000];
void bulidv(int in, int l, int r)
{
    if (l == r)
    {
        seg[in] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    bulidv(in * 2, l, mid);
    bulidv(in * 2 + 1, mid + 1, r);
    seg[in] = seg[in * 2 + 1] + seg[in * 2];
}
void change(int in, int poschange, int val, int l, int r)
{
    if (poschange < l || poschange > r)
        return;
    if (l == r)
    {
        seg[in] += val;
        return;
    }
    int mid = (l + r) / 2;
    change(in * 2, poschange, val, l, mid)
    change(in * 2 + 1, poschange, val, mid + 1, r);
    seg[in] = seg[in * 2] + seg[in * 2 + 1];
    // cout << seg[in].first << ' ' << l << ' ' << r << '\n';
}
int query(int curin, int curl, int curr, int ql, int qr)
{
    if (ql > curr || qr < curl)
        return 0;
    if (ql <= curl && curr <= qr)
        return seg[curin];
    int mid = (curl + curr) / 2;
    return query(curin * 2, curl, mid, ql, qr) + query(curin * 2 + 1, mid + 1, curr, ql, qr);
}
signed main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    bulidv(1, 1, n);
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            l++;
            cout << query(1, 1, n, l, r) << "\n";
        }
        else if (type == 0)
        {
            int x, d;
            cin >> x >> d;
            x++;
            change(1, x, d, 1, n);
        }
    }
}