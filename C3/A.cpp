#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll dp[305][305]; 
int a[305];      

int main() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        cin >> a[i];
    }

    
    for (int l = 2; l <= n; ++l) {
        for (int i = 1; i + l - 1 <= n; ++i) {
            int j = i + l - 1;
            dp[i][j] = LLONG_MAX; 
            for (int k = i; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + (ll)a[i-1] * a[k] * a[j]);
            }
        }
    }
    
    cout << dp[1][n] << endl;
    return 0;
}