#include <bits/stdc++.h>
using namespace std;
#define MOVE(a, b)                                   \
  moves.emplace_back(a + 1, b + 1),                  \
      waste[b].push_back(waste[a].back()),           \
      waste[a].pop_back(),                           \
      everything[b].push_back(everything[a].back()), \
      everything[a].pop_back();
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	n--;
	map<int, int> mii;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			mii[i + 1]++;
	vector<pair<int, int>> moves;
	vector<vector<int>> target(n + 1);
	for (int i = 0; i < target.size(); i++)
	{
		int x;
		cin >> x;
		target[i].resize(x);
		for (auto& a : target[i])
			cin >> a;
	}
	vector<vector<int>> everything(n + 1);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			everything[i].push_back(i + 1);
	vector<deque<int>> waste(n + 1);
	for (int i = 0; i < n; i++)
		waste[i].resize(m, i + 1);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n + 1; j++)
		{
			// if (i == m - 1 && j == n && i < target[j].size())
			// {
			// 	// cout<<"X\n";
			// 	int in;
			// 	for (int k = 0; k < waste.size(); k++)
			// 		if (!waste[k].empty())
			// 			in = k;
			// 	if (in != j)
			// 		moves.emplace_back(in, j);
			// 	continue;
			// }
			vector<int> still;
			for (int k = 0; k < n + 1; k++)
				if (m > everything[k].size() && k != j)
					still.push_back(k);
			for (auto a : still)
				while (!waste[j].empty() && m > everything[a].size())
					MOVE(j, a);
			map<int, int> idkbro;
			for (int k = 0; k < n + 1; k++)
				if (!waste[k].empty())
					idkbro[waste[k].back()]++;
			if (idkbro.size() + 1 == mii.size())
			{
				int target = 0;
				for (auto a : mii)
					target += a.first;
				for (auto a : idkbro)
					target -= a.first;
				int dupe = -1;
				for (auto a : idkbro)
					if (a.second == 2)
						dupe = a.first;
				pair<int, int> coords;
				for (int k = 0; k < n + 1; k++)
					for (int l = 0; l < waste[k].size(); l++)
						if (waste[k][l] == target)
						{
							coords = { k, l };
							goto A;
						}
			A:
				if (dupe == -1)
				{
					for (int k = waste[coords.first].size() - 1; k > coords.second; k--)
						MOVE(coords.first, j);
					for (int k = 0; k < n; k++)
						if (waste[k].empty() && everything[k].size() < m)
						{
							MOVE(coords.first, k);
							break;
						}
					while (!waste[j].empty())
						MOVE(j, coords.first);
				}
				else
				{
					int smth;
					for (int k = 0; k < n + 1; k++)
						if (!waste[k].empty())
							if (waste[k].back() == dupe && k != coords.first)
							{
								smth = k;
								break;
							}
					while (waste[coords.first].size() > coords.second + 1)
						MOVE(coords.first, j);
					MOVE(smth, j);
					MOVE(coords.first, smth);
					while (!waste[j].empty())
						MOVE(j, coords.first);
				}
			}
			if (target[j].size() > i)
			{
				for (int k = 0; k < n + 1; k++)
					if (!waste[k].empty())
						if (k != j && waste[k].back() == target[j][i])
						{
							moves.emplace_back(k + 1, j + 1);
							everything[j].push_back(everything[k].back());
							everything[k].pop_back();
							waste[k].pop_back();
							break;
						}
				mii[target[j][i]]--;
				if (mii[target[j][i]] == 0)
					mii.erase(target[j][i]);
			}
		}
	cout << moves.size() << '\n';
	for (auto a : moves)
		cout << a.first << ' ' << a.second << '\n';
}