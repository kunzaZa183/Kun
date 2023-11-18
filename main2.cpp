#include <bits/stdc++.h>
using namespace std;
int arr[10001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tests;
	cin >> tests;
	while (tests--)
	{
		int n, k;
		cin >> n >> k;
		vector<pair<int, int>> vpii;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			vpii.emplace_back(x, -1);
		}
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			vpii.emplace_back(x, 1);
		}
		sort(vpii.begin(), vpii.end());
		int maxnum = vpii.back().first;
		int in = 0, cur = 0;
		for (int i = 1; i <= maxnum; i++)
		{
			while (in < vpii.size())
			{
				if (vpii[in].first != i)
					break;
				cur += vpii[in].second;
				in++;
			}
			arr[i] = arr[i - 1] + cur;
		}
		int endl = -1, endr = -1;
		for (int i = 1; i <= maxnum; i++)
		{
			int l = i, r = maxnum;
			while (l < r)
			{
				int mid = (l + r) / 2;
				if (arr[mid] - arr[i - 1] == k)
				{
					endl = i, endr = mid + 1;
					break;
				}
				else if (arr[mid] - arr[i - 1] > k)
					r = mid - 1;
				else if (arr[mid] - arr[i - 1] < k)
					l = mid + 1;
			}
			if (arr[l] - arr[i - 1] == k)
				endl = i, endr = l + 1;
		}
		if (endl == -1)
			cout << "IMPOSSIBLE\n";
		else
			cout << endl
			<< ' ' << endr << "\n";
	}
}