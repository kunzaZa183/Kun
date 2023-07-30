#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adjmatrix;
vector<int> curvi;
vector<vector<int>> dp;
int m;
int minans;
void recur(int in)
{
	if (in == curvi.size())
	{
		vector<int> idk(m, 0);
		for (int i = 0; i < curvi.size(); i++)
			idk[curvi[i]] += (1 << i);
		int minthis = INT_MIN;
		for (auto a : idk)
		{
			int mini = INT_MAX;
			if (a == 0)
				mini = 0;
			for (int i = 0; i < curvi.size(); i++)
				if ((1 << i) & a)
					mini = min(mini, dp[i][a]);
			minthis = max(minthis, mini);
		}
		minans = min(minans, minthis);
		return;
	}
	for (int i = 0; i < m; i++)
	{
		curvi[in] = i;
		recur(in + 1);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while (cin >> n, n != 0)
	{
		int p;
		cin >> m >> p;
		adjmatrix.clear();
		adjmatrix.resize(n, vector<int>(n, 100));
		for (int i = 0; i < p; i++)
		{
			string s;
			cin >> s;
			adjmatrix[s[0] - 'A'][s[1] - 'A'] = 1, adjmatrix[s[1] - 'A'][s[0] - 'A'] = 1;
		}
		dp.clear();
		dp.resize(n, vector<int>((1 << n), 200));
		queue<tuple<int, int, int>> qpii;
		qpii.emplace(0, 1, 0);
		while (!qpii.empty())
		{
			auto [cur, mask, val] = qpii.front();
			qpii.pop();
			if (dp[cur][mask] > val)
			{
				dp[cur][mask] = val;
				for (int i = 0; i < n; i++)
					if (adjmatrix[cur][i] == 1)
						qpii.emplace(i, mask | (1 << i), val + adjmatrix[cur][i]);
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = (1 << n) - 1; j >= 0; j--)
			{
				for (int k = 0; k < n; k++)
					if ((1 << k) & j)
						dp[i][j ^ (1 << k)] = min(dp[i][j ^ (1 << k)], dp[i][j]);
			}
		}
		minans = 100;
		curvi.clear();
		curvi.resize(n);
		recur(0);
		cout << minans << '\n';
	}
}