#include <bits/stdc++.h>
using namespace std;
const int MX = 101;
vector<int> V1[MX];
vector<int> V2[MX];
bool vis1[MX];
bool vis2[MX];
int n, m;
int cnt1, cnt2;
void dfs1(int start) {
    vis1[start] = 1;

    for(int i=0; i<V1[start].size(); i++) {
        int nxt = V1[start][i];
        if(vis1[nxt]) continue;
        cnt1++;
        vis1[nxt]=1;
        dfs1(nxt);
    }
}
void dfs2(int start) {
    vis2[start] = 1;

    for(int i=0; i<V2[start].size(); i++) {
        int nxt = V2[start][i];
        if(vis2[nxt]) continue;
        cnt2++;
        vis2[nxt]=1;
        dfs2(nxt);
    }
}
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        V1[x].push_back(y);
        V2[y].push_back(x);
    }
    int mid = (n+1)/2;
    int ans = 0;
    for(int i=1; i<=n; i++) {
        dfs1(i);
        dfs2(i);
        if(cnt1>=mid || cnt2>=mid) {
            ans++;
        }
        cnt1 = cnt2 = 0;
        fill(vis1, vis1+MX, 0);
        fill(vis2, vis2+MX, 0);
    }
    cout << ans;
}
