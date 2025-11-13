#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int p[505], n;
int dp[505][505], root[505][505];
int lchild[505], rchild[505], prefix[505];

void build(int l, int r, int parent, bool is_left) {
    if (l > r) return;
    
    int rt = root[l][r];
    
    if (parent != -1) {
        if (is_left) lchild[parent] = rt;
        else rchild[parent] = rt;
    }
    
    build(l, rt - 1, rt, true);
    build(rt + 1, r, rt, false);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        prefix[i] = prefix[i - 1] + p[i];
        dp[i][i] = p[i];  
        root[i][i] = i;
    }
    
    
    for (int i = n; i >= 1; i--) {
        for (int j = i + 1; j <= n; j++) {
            dp[i][j] = INF;
            for (int k = root[i][j - 1]; k <= root[i + 1][j]; k++) {
                int left_cost = (k > i) ? dp[i][k - 1] : 0;
                int right_cost = (k < j) ? dp[k + 1][j] : 0;
                int total = left_cost + right_cost + prefix[j] - prefix[i - 1];
                
                if (total < dp[i][j]) {
                    dp[i][j] = total;
                    root[i][j] = k;
                }
            }
        }
    }
    memset(lchild, -1, sizeof(lchild));
    memset(rchild, -1, sizeof(rchild));
    
    build(1, n, -1, false);
    
    cout << dp[1][n] << endl;

    for (int i = 1; i <= n; i++) {
        cout << lchild[i] << " " << rchild[i] << endl;
    }
    
    return 0;
}