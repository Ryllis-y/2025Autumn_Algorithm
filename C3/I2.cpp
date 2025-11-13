#include <bits/stdc++.h>
using namespace std;

bool dp[101][51][201][2]; // i, j, pos, dir

int main() {
    string s;
    int n;
    cin >> s >> n;
    int len = s.length();
    const int pianyi = len; // 位置偏移量
    
    dp[0][0][pianyi][0] = true; // 初始位置0，方向正
    
    for (int i = 0; i < len; i++) {
        for (int j = 0; j <= n; j++) {
            for (int pos = 0; pos <= 2*len; pos++) {
                for (int dir = 0; dir < 2; dir++) {
                    if (!dp[i][j][pos][dir]) continue;
                    
                    if (s[i] == 'F') {
                        int newpos = pos + (dir == 0 ? 1 : -1);
                        dp[i+1][j][newpos][dir] = true;
                    } else { // 'T'
                        dp[i+1][j][pos][1-dir] = true;
                    }
                    
                    // 修改（消耗一次修改次数）
                    if (j+1 <= n) {
                        if (s[i] == 'F') {
                            dp[i+1][j+1][pos][1-dir] = true;
                        } else { // 'T'
                            int newpos = pos + (dir == 0 ? 1 : -1);
                            dp[i+1][j+1][newpos][dir] = true;
                        }
                    }
                }
            }
        }
    }
    
    int ans = 0;
    for (int pos = 0; pos <= 2*len; pos++) {
        for (int dir = 0; dir < 2; dir++) {
            if (dp[len][n][pos][dir]) {
                ans = max(ans, abs(pos - pianyi));
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}