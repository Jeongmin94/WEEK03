#include <bits/stdc++.h>
using namespace std;
const int MX = 1001;
int board[MX][MX];
bool vis[MX];
int n, m, v;
void DFS(int start) {
    cout << start + 1 << ' ';
    vis[start] = 1;
    for(int i=0; i<n; i++) {
        if(vis[i] || board[start][i] == 0) continue;
        vis[i] = 1;
        DFS(i);
    }
}
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m >>v;

    for(int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        board[x-1][y-1] = board[y-1][x-1] = 1;
    }
    // DFS
    DFS(v-1);
    cout << '\n';
    fill(vis, vis+n, 0);

    // BFS
    queue<int> Q;
    Q.push(v-1);
    vis[v-1] = 1;
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        cout << cur + 1<< ' ';
        for(int i=0; i<n; i++) {
            if(vis[i] || board[cur][i] == 0) continue;
            vis[i] = 1;
            Q.push(i);
        }
    }
}
