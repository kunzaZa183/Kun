#include <bits/stdc++.h>
using namespace std;
const int maxn = 350, BIGNUM = 100000;
int arr[maxn + 1], qsum[maxn + 1], dp[maxn + 1][maxn + 1][maxn + 1];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, actualk;
	cin >> n >> actualk;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	sort(arr + 1, arr + 1 + n, greater<int>());
	for (int i = 1; i <= n; i++)
		qsum[i] += qsum[i - 1] + arr[i];
	for (int i = 1; i <= maxn; i++)
		for (int j = 1; j <= maxn; j++)
			for (int k = 1; k <= maxn; k++)
				dp[i][j][k] = BIGNUM;
	for (int i = 1; i <= maxn; i++)
		for (int j = i + 1; j <= maxn; j++)
			for (int numleft = 0; numleft <= (j - i + 1); numleft++)
			{
				int numright = j - i + 1 - numleft;
				dp[1][i][j] = min(dp[1][i][j], (qsum[i - 1 + numleft] - qsum[i - 1]) * (numleft - 1) + (qsum[j] - qsum[i + numleft - 1]) * (numright - 1) + 2 * numleft * numright);
			}
	for (int k = 2; k <= actualk; k++)
		for (int i = 1; i <= n; i++)
			for (int j = i + 2 * k - 1; j <= n; j++)
				for (int x = i; x < n / k + i + 1 && x < j; x++)
					for (int y = x + 1; y <= j; y++)
					{
						dp[k][i][j] = min(dp[k][i][j], dp[k - 1][x + 1][y - 1] + (x - i) * (qsum[x] - qsum[i - 1]) + (j - y) * (qsum[j] - qsum[y - 1]) + 2 * (x - i + 1) * (j - y + 1));
					}
	cout << dp[actualk][1][n] << "\n";
}