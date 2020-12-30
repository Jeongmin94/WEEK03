#include <bits/stdc++.h>
using namespace std;
const int MX = 102;
vector<pair<int, int>> V[MX];
int degree[MX];
int ans[MX][MX];
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n; cin >> n;
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int x, y, k;
		cin >> x >> y >> k;
		V[y].push_back({ x,k });
		degree[x]++;
	}
	queue<int> Q;
	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) {
			ans[i][i] = 1;
			Q.push(i);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		int cur = Q.front(); Q.pop();
		for (int j = 0; j < V[cur].size(); j++) {
			pair<int, int> nxt = V[cur][j];
			for (int idx = 1; idx <= n; idx++) {
				ans[nxt.first][idx] += ans[cur][idx] * nxt.second;
			}
			degree[nxt.first]--;
			if (degree[nxt.first] == 0) Q.push(nxt.first);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (ans[i][i] == 1)
			cout << i << ' ' << ans[n][i] << '\n';
	}
}
