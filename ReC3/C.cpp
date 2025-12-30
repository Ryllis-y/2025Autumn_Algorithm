#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll trans[3][3], pipe[3][10007], dp[3][10007];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int m;
        cin >> m;
        memset(trans, 0, sizeof(trans)), memset(pipe, 0, sizeof(pipe)), memset(dp, 0x3f, sizeof(dp));
        dp[0][0] = dp[1][0] = dp[2][0] = 0;
        for (int i = 0; i < 3; i++){
            for (int j = 1; j <= m; j++){
                cin >> pipe[i][j];
                if (j == 1){
                    dp[i][j] = pipe[i][j];
                }
            }
        }
        
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                cin >> trans[i][j];
            }
        }

        for (int j = 2; j <= m; j++){
            for (int i = 0; i < 3; i++){
                for (int k = 0; k < 3; k++){
                    dp[i][j] = min(dp[i][j], dp[k][j - 1] + pipe[i][j] + trans[k][i]);
                }
            }
        }
        cout << min(min(dp[0][m], dp[1][m]), dp[2][m]) << endl;
    }
    return 0;
}