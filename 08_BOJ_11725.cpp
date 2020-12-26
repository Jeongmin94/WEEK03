#include <bits/stdc++.h>
using namespace std;
const int MX = 100002;
vector<vector<int>> board(MX);
bool vis[MX];
int par[MX];
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        board[x].push_back(y);
        board[y].push_back(x);
    }
    queue<int> Q;
    Q.push(1);
    vis[1] = 1;
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for (int i = 0; i < board[cur].size(); i++) {
            if (vis[board[cur][i]]) continue;
            int nxt = board[cur][i];
            vis[board[cur][i]] = 1;
            par[nxt] = cur;
            Q.push(nxt);
        }
    }
    for (int i = 2; i <= n; i++) {
        cout << par[i] << '\n';
    }
}
