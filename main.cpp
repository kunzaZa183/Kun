#include <bits/stdc++.h>
using namespace std;
const int fiveeight = 390625, base = 5, digits = 8;
int dist[fiveeight];
int xbit(int num, int x) // 0 based, right to left
{
	while (x--)
		num /= base;
	return num % base;
}
int gpow(int a, int b)
{
	int num = 1;
	while (b--)
		num *= a;
	return num;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < fiveeight; i++)
		dist[i] = INT_MAX;
	queue<pair<int, int>> qs; // state dist
	for (int i = 0; i < (1 << digits); i++)
	{
		int num = 0;
		for (int j = digits - 1; j >= 0; j--)
		{
			num *= base;
			if ((1 << j) & i)
			{
				num += base - 1;
				continue;
			}
			num += j / 2;
		}
		qs.emplace(num, 0);
	}
	while (!qs.empty())
	{
		pair<int, int> tmp = qs.front();
		qs.pop();
		if (dist[tmp.first] == INT_MAX)
		{
			dist[tmp.first] = tmp.second;
			int nextnum1 = 0, nextnum2 = 0, nextnum3 = 0, nextnum4 = 0;
			for (int j = digits - 1; j >= 0; j--)
			{
				nextnum1 *= base, nextnum2 *= base, nextnum3 *= base, nextnum4 *= base;
				int val = xbit(tmp.first, j);
				if (val == 4)
				{
					nextnum1 += 4, nextnum2 += 4, nextnum3 += 4, nextnum4 += 4;
					continue;
				}
				int a = val >> 1, b = val % 2, m = j % 2;
				nextnum1 += ((a & b) << 1) + b;
				nextnum2 += ((a | b) << 1) + b;
				nextnum3 += (a << 1) + a ^ b;
				nextnum4 += (a << 1) + b ^ m;
			}
			qs.emplace(nextnum1, tmp.second + 1);
			qs.emplace(nextnum2, tmp.second + 1);
			qs.emplace(nextnum3, tmp.second + 1);
			qs.emplace(nextnum4, tmp.second + 1);
		}
	}
	int tests;
	cin >> tests;
	while (tests--)
	{
		int a, b, c, d, m;
		cin >> a >> b >> c >> d >> m;
		int num = 0;
		for (int i = 0; i < digits; i++)
		{
			num *= base;
			num += base - 1;
		}
		for (int i = 0; i < 30; i++)
		{
			int a2 = bool(a & (1 << i)), b2 = bool(b & (1 << i)), c2 = bool(c & (1 << i)), d2 = bool(d & (1 << i)), m2 = bool(m & (1 << i));
			int val = xbit(num, (a2 << 2) + (b2 << 1) + m2);
			if (val == 4)
			{
				num -= val * gpow(5, (a2 << 2) + (b2 << 1) + m2);
				num += ((c2 << 1) + d2) * gpow(5, (a2 << 2) + (b2 << 1) + m2);
			}
			else if (val != ((c2 << 1) + d2))
			{
				cout << "-1\n";
				goto A;
			}
		}
		if (dist[num] == INT_MAX)
			cout << "-1\n";
		else
			cout << dist[num] << "\n";
	A:;
	}
}