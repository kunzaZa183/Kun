#include <bits/stdc++.h>
using namespace std;
#define int long long
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
		vector<tuple<vector<int>, int, int>> vpivii;
		int lastc = 0;
		vpivii.emplace_back(vector<int>(), 1, 0);
		for (int i = 0; i < n; i++)
		{
			int tp, x;
			cin >> tp >> x;

			auto& [a, b, c] = vpivii.back();
			if (tp == 1)
			{
				a.push_back(x);
				c++;
			}
			else
			{
				b = x + 1;
				c = (lastc + a.size()) * b;
				if (c < lastc)
					c = LLONG_MAX;
				lastc = c;
				vpivii.emplace_back(vector<int>(), 1, c);
			}
		}
		for (int i = 0; i < q; i++)
		{
			int query;
			cin >> query;
			query--;
			while (1)
			{
				for (int i = 0; i < vpivii.size(); i++)
				{
					auto& [a, b, c] = vpivii[i];
					if (c > query)
					{
						if (i == 0)
						{
							query %= c / b;
							if (query >= c / b - a.size())
							{
								cout << a[query - (c / b - a.size())] << ' ';
								goto A;
							}
							else
								break;
						}
						else
						{
							query %= get<2>(vpivii[i - 1]) + a.size();
							if (query >= get<2>(vpivii[i - 1]))
							{
								cout << a[query - (get<2>(vpivii[i - 1]))] << ' ';
								goto A;
							}
							else
								break;
						}
					}
				}
			}
		A:;
		}
		cout << '\n';
	}
}