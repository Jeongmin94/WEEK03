#include <bits/stdc++.h>
using namespace std;
const int MX = 100002;
int coin[101];
int dp[MX];
int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        cin >> coin[i];
    }
    fill(dp, dp+MX, MX);
    dp[0] = 0;
    // dp[k] = min(dp[k], dp[k-x] + 1)
    for(int i=1; i<100001; i++) {
        for(int j=0; j<n; j++){
            if(i-coin[j]<0) continue;
            dp[i] = min(dp[i], dp[i-coin[j]]+1);
        }
    }
    if(dp[k] > k) cout << -1;
    else cout << dp[k];
}
