#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main() {
    int n;
    ll V;
    cin >> n >> V;
    vector<ll> v(n), w(n);
    int max_w = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i] >> w[i];
        max_w += w[i];
    }

    vector<ll> dp(max_w + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = max_w; j >= w[i]; j--) {
            if (dp[j - w[i]] != INF) {
                dp[j] = min(dp[j], dp[j - w[i]] + v[i]);
            }
        }
    }

    int ans = 0;
    for (int j = 0; j <= max_w; j++) {
        if (dp[j] <= V) {
            ans = max(ans, j);
        }
    }
    cout << ans << endl;
    return 0;
}