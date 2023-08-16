#include <bits/stdc++.h>
using namespace std;

#define int long long
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)

const int maxn = 505;
bool con[maxn][maxn], inq[maxn][maxn];
int n;
char grid[maxn][maxn];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void pr(queue<pi> q) {
	while (sz(q)) {
		auto [x, y] = q.front(); q.pop();
		cout << x << " " << y << endl;
	}
	cout << endl;
}

pair<int, int> to(int x, int y, int k) {
	return { x + dx[k], y + dy[k] };
}

bool inrange(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < n;
}

bool onedge(int x, int y) {
	return x == 0 || y == 0 || x == n - 1 || y == n - 1;
}

queue<pair<int, int>> tq;

void set_con(int s, int t) {
	queue<pair<int, int>> q;
	q.push({ s, t });
	con[s][t] = true;

	while (sz(q)) {
		auto [x, y] = q.front(); q.pop();
		//cout << x << " " << y << endl;
		for (int i = 0; i < 4; i++) {
			auto [nx, ny] = to(x, y, i);
			if (inrange(nx, ny) && !con[nx][ny] && grid[nx][ny] == '.') {
				con[nx][ny] = true;
				q.push({ nx, ny });
			}
			else if (inrange(nx, ny) && !inq[nx][ny] && grid[nx][ny] == 'T') {
				inq[nx][ny] = true;
				tq.push({ nx, ny });
			}
		}
	}
}

//change inq to false and grid to .

void solve() {
	while (sz(tq)) tq.pop();

	cin >> n;
	int k; cin >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			con[i][j] = false;
			inq[i][j] = false;
			cin >> grid[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (onedge(i, j) && grid[i][j] == '.') {
				set_con(i, j);
			}
			else if (onedge(i, j) && !inq[i][j] && grid[i][j] == 'T') {
				inq[i][j] = true;
				tq.push({ i, j });
			}
		}
	}

	vector<vector<string>> ans(n, vector<string>(n, "."));
	int epoch = 1;
	while (sz(tq)) {
		//pr(tq);
		vector<pi> todo;
		for (int i = 0; i < k && sz(tq); i++) {
			auto [x, y] = tq.front();
			todo.push_back({ x, y });
			grid[x][y] = '.';
			inq[x][y] = false;
			ans[x][y] = to_string(epoch);
			tq.pop();
		}

		for (auto [x, y] : todo) {
			set_con(x, y);
		}
		/*
		for (int i=0;i<n;i++) {
				for (int j=0;j<n;j++) {
						cout << con[i][j] << " ";
				}
				cout << endl;
		}
		cout << endl;
		 */

		epoch++;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cout << ans[i][j] << " ";
		cout << "\n";
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int tc; cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}