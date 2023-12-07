#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		adjlist[a - 1].push_back(b - 1), adjlist[b - 1].push_back(a - 1);
	}
	used.reset();
	eachcent(0, n, -1);
	cout << *allans.rbegin() << '\n';
	while (m--)
	{
		int in, val;
		cin >> in >> val;
		in--;
		int change = val - arr[in];
		arr[in] = val;

		allans.erase(allans.find(oldans[in]));
		oldans[in] = sumfirsttwo(alldowncent[in]) + arr[in];
		allans.insert(oldans[in]);
		int orig = in;
		in = parcent[in];
		while (in != -1)
		{
			allans.erase(allans.find(oldans[in]));
			curcent = in;
			int nextroot = parnextroot[in][orig];

			ql = starttime[in][nextroot], qr = endtime[in][nextroot] - 1;
			int ql2 = ql, qr2 = qr;
			alldowncent[in].erase(alldowncent[in].find(query(0, 0, segtree[curcent].size() / 4 - 1)));

			ql = starttime[in][orig], qr = endtime[in][orig] - 1, ::val = change;
			update(0, 0, segtree[curcent].size() / 4 - 1);

			ql = ql2, qr = qr2;
			alldowncent[in].insert(query(0, 0, segtree[curcent].size() / 4 - 1));
			oldans[in] = sumfirsttwo(alldowncent[in]) + arr[in];
			allans.insert(oldans[in]);
			in = parcent[in];
		}
		cout << *allans.rbegin() << '\n';
	}
}