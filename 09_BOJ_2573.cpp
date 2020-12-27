#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
const int MX = 302;
int board[MX][MX];
int copyB[MX][MX];
bool vis[MX][MX];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    queue<pair<int, int>> Q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            copyB[i][j] = board[i][j];

        }
    }
    int year = -1;
    int area = 0;
    while (1)
    {
        year++;
        area = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] || board[i][j] == 0) continue;
                area++;
                queue<pair<int, int>> Q;
                Q.push({ i,j });
                vis[i][j] = 1;
                while (!Q.empty()) {
                    auto cur = Q.front(); Q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (board[nx][ny] == 0) {
                            if (copyB[cur.X][cur.Y] > 0) copyB[cur.X][cur.Y]--;
                            continue;
                        }
                        if (vis[nx][ny]) continue;
                        Q.push({ nx,ny });
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
        if (area == 0) {
            cout << 0;
            break;
        }
        if (area >= 2) {
            cout << year;
            break;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                board[i][j] = copyB[i][j];
            }
            fill(vis[i], vis[i] + MX, 0);
        }
    }
}
