#include <bits/stdc++.h>
using namespace std;
const int MX = 32002;
vector<int> V[MX];
bool vis[MX];
stack<int> S;
int n, m;
void topo(int v) {
    vis[v] = 1;

    for(int i=0; i<V[v].size(); i++) {
        if(vis[V[v][i]]) continue;
        vis[V[v][i]] = 1;
        topo(V[v][i]);
    }
    S.push(v);
}
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        V[x].push_back(y);
    }
  
    for(int i=1; i<=n; i++) {
        if(vis[i]) continue;
        topo(i);
    }

    while(!S.empty()) {
        cout << S.top() << ' ';
        S.pop();
    }
}
