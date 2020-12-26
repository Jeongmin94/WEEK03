#include <bits/stdc++.h>
using namespace std;
const int MX = 10002;
vector<int> V[MX];
bool vis[MX];
int n, m, v;
void dfs(int start) {
	cout << start << ' ';
	for (int i = 0; i < V[start].size(); i++) {
		if (vis[V[start][i]]) continue;
		vis[V[start][i]] = 1;
		dfs(V[start][i]);
	}
}
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		V[x].push_back(y);
		V[y].push_back(x);
	}
	for (int i = 0; i <= n; i++) {
		sort(V[i].begin(), V[i].end());
	}
	// DFS
	vis[v] = 1;
	dfs(v);
	cout << '\n';
	fill(vis, vis + MX, 0);
	// BFS
	queue<int> Q;
	Q.push(v);
	vis[v] = 1;
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		cout << cur << ' ';
		for (int i = 0; i < V[cur].size(); i++) {
			if (vis[V[cur][i]]) continue;
			Q.push(V[cur][i]);
			vis[V[cur][i]] = 1;
		}
	}
}
