#include <bits/stdc++.h>
using namespace std;
const int MX = 22;
string board[MX];
bool vis[26];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int r, c;
int ans;
void dfs(int x, int y, int depth) {
	ans = max(ans, depth);
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
		if (vis[board[nx][ny] - 'A']) continue;
		vis[board[nx][ny] - 'A'] = 1;
		dfs(nx, ny, depth + 1);
		vis[board[nx][ny] - 'A'] = 0;
	}
}
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> board[i];
	}
	vis[board[0][0] - 'A'] = 1;
	dfs(0, 0, 1);
	cout << ans;
}
