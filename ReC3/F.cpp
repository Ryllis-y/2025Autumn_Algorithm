#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll value[10007], dp[10007];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> value[i];
    }

    for (int i = 1; i <= n; i++){
        ll mx = value[i];
        for (int j = 1; j <= i && j <= k; j++){
            mx = max(mx, value[i - j + 1]);
            dp[i] = max(dp[i], dp[i - j] + j * mx);
        }
    }
    cout << dp[n] << endl;
    return 0;
}