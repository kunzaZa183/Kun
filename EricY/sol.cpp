#include <bits/stdc++.h>
using namespace std;
#define MOVE(a, b)                         \
  moves.emplace_back(a + 1, b + 1),        \
      waste[b].push_back(waste[a].back()), \
      waste[a].pop_back();
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
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
	vector<int> capa(n + 1, m);
	vector<deque<int>> waste(n + 1);
	for (int i = 0; i < n; i++)
		waste[i].resize(m, i + 1);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n + 1; j++)
		{
			vector<int> still;
			for (int k = 0; k < n + 1; k++)
				if (waste[k].size() < capa[k] && k != j)
					still.push_back(k);
			if (still.size() == 1)
				while (!waste[j].empty())
					MOVE(j, still[0])
			else
			{
				int mini = INT_MAX, minid;
				for (auto a : still)
					if (capa[a] - waste[a].size() < mini)
					{
						mini = capa[a] - waste[a].size();
						minid = a;
					}
				if (!waste[j].empty())
					MOVE(j, minid);
				for (auto a : still)
					while (!waste[j].empty() && waste[a].size() < capa[a] && a != minid)
						MOVE(j, a);
			}
			if (target[j].size() > i)
			{
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
					int dupe;
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
				for (int k = 0; k < n + 1; k++)
					if (!waste[k].empty())
						if (k != j && waste[k].back() == target[j][i])
						{
							moves.emplace_back(k + 1, j + 1);
							waste[k].pop_back();
							break;
						}
				mii[target[j][i]]--;
				if (mii[target[j][i]] == 0)
					mii.erase(target[j][i]);
			}
			capa[j]--;
		}
	cout << moves.size() << '\n';
	for (auto a : moves)
		cout << a.first << ' ' << a.second << '\n';
}