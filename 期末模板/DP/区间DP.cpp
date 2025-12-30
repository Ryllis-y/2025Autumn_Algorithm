#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 307;
ll dp[maxn][maxn], arr[maxn], sum[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
    }
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i++){
        dp[i][i] = 0;
    }
    for (int len = 2; len <= n; len++){
        for (int l = 1; l + len - 1 <= n; l++){
            int r = l + len - 1;
            for (int k = l; k < r; k++){
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + sum[r] - sum[l - 1]);
            }
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}


