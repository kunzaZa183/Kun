#include <bits/stdc++.h>
using namespace std;
#define int long long
const int big = 4'000'000'000'000'000'000;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, a, b, c, x;
	cin >> n >> a >> b >> c >> x;
	if (b > c)
		swap(b, c);
	int ways = 0;
	for (int i = 1; i <= n; i++)
	{
		int cur = x - i * a;
		int tmpb = b, tmpc = c;
		int gcdi = gcd(tmpb, tmpc);
		if (cur % gcdi != 0)
			continue;
		cur /= gcdi;
		tmpb /= gcdi, tmpc /= gcdi;
		int ansb, ansc;
		if (tmpb == 1)
		{
			ansb = 1;
			ansc = 0;
		}
		else
		{
			vector<pair<int, int>> vpii;
			vpii.emplace_back(tmpc, tmpb);
			while (vpii.back().second != 1)
				vpii.emplace_back(vpii.back().second, vpii.back().first % vpii.back().second);
			vpii.pop_back();
			ansb = 1;
			ansc = -(vpii.back().first - 1) / vpii.back().second;
			for (int j = vpii.size() - 2; j >= 0; j--)
			{
				ansb = ansc;
				ansc = (1 - ansb * vpii[j].first) / vpii[j].second;
			}
			swap(ansb, ansc);
		}
		int down = cur / tmpb;
		cur %= tmpb;
		ansb *= cur, ansc *= cur;
		ansb += down;

		int x;
		if (ansb > 1)
			x = -((ansb - 1) / tmpc);
		else if ((1 - ansb) % tmpc == 0)
			x = (1 - ansb) / tmpc;
		else
			x = (1 - ansb) / tmpc + 1;

		int w;
		if (ansb < n)
			w = (n - ansb) / tmpc;
		else if ((ansb - n) % tmpc == 0)
			w = -((ansb - n) / tmpc);
		else
			w = -((ansb - n) / tmpc) - 1;

		int y;
		if (ansc > 1)
			y = -((ansc - 1) / tmpb);
		else if ((1 - ansc) % tmpb == 0)
			y = (1 - ansc) / tmpb;
		else
			y = (1 - ansc) / tmpb + 1;
		y = -y;

		int z;
		if (ansc < n)
			z = (n - ansc) / tmpb;
		else if ((ansc - n) % tmpb == 0)
			z = -((ansc - n) / tmpb);
		else
			z = -((ansc - n) / tmpb) - 1;
		z = -z;

		ways += max(0LL, min(w, y) - max(x, z) + 1);
	}
	cout << ways << "\n";
}