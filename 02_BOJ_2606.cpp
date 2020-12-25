#include <bits/stdc++.h>
using namespace std;
const int MX = 101;
int board[MX][MX];
bool vis[MX];
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        board[x - 1][y - 1] = board[y - 1][x - 1] = 1;
    }
   
    queue<int> Q;
    Q.push(0);
    vis[0] = 1;
    int cnt = 0;
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for (int i = 0; i < n; i++) {
            if (vis[i] || board[cur][i] == 0) continue;
            board[cur][i] = 0;
            board[i][cur] = 0;
            cnt++;
            vis[i] = 1;
            Q.push(i);
        }
    }
    cout << cnt;
}
