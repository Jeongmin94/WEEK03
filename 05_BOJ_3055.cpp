#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
const int MX = 52;
string board[MX];
int dist[MX][MX];
int flood[MX][MX];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int r, c;
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		cin >> board[i];
	}
	queue<pair<int, int>> sQ;
	queue<pair<int, int>> fQ;
	pair<int, int> ans;
	for (int i = 0; i < r; i++) {
		fill(dist[i], dist[i] + c, -1);
		fill(flood[i], flood[i] + c, -1);
		for (int j = 0; j < c; j++) {
			if (board[i][j] == 'S') sQ.push({ i,j });
			if (board[i][j] == '*') fQ.push({ i,j });
			if (board[i][j] == 'D') ans = { i,j };
		}
	}

	// flood BFS
	flood[ans.X][ans.Y] = -2;
	flood[fQ.front().X][fQ.front().Y] = 0;
	while (!fQ.empty()) {
		auto cur = fQ.front(); fQ.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (board[nx][ny] == 'X'||board[nx][ny]=='D' || flood[nx][ny] >= 0) continue;
			flood[nx][ny] = flood[cur.X][cur.Y] + 1;
			fQ.push({ nx,ny });
		}
	}

	// S BFS
	dist[sQ.front().X][sQ.front().Y]=0;
	while (!sQ.empty()) {
		auto cur = sQ.front(); sQ.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx == ans.X && ny == ans.Y) {
				cout << dist[cur.X][cur.Y] + 1;
				return 0;
			}
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (board[nx][ny] == 'X' || dist[nx][ny] >= 0) continue;
			if (flood[nx][ny] != -1 && dist[cur.X][cur.Y] + 1 >= flood[nx][ny]) continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			sQ.push({ nx,ny });
		}
	}
	cout << "KAKTUS";
}
