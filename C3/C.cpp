#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;

ll p[3][10007];  
ll t[3][3];     

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int m;
        cin >> m;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> p[i][j];
            }
        }
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cin >> t[i][j];
            }
        }

        vector<ll> dp_prev(3, 0);
        vector<ll> dp_curr(3, 0);
        
        for (int i = 0; i < 3; ++i) {
            dp_prev[i] = p[i][0];
        }

        for (int j = 1; j < m; ++j) {
            for (int i = 0; i < 3; ++i) { 
                dp_curr[i] = inf;
                for (int k = 0; k < 3; ++k) {  
                    ll cost = dp_prev[k] + t[k][i] + p[i][j];
                    dp_curr[i] = min(dp_curr[i], cost);
                }
            }
            swap(dp_prev, dp_curr);
        }
        ll ans = min({dp_prev[0], dp_prev[1], dp_prev[2]});
        cout << ans << '\n';
    }
    
    return 0;
}