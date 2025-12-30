#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[20][20];
int digit[20];

ll dfs(int pos, int pre, bool limit, bool lead){
    if (pos == 0) return 1;
    if (!limit && !lead && dp[pos][pre] != -1) return dp[pos][pre];
    int up = limit ? digit[pos] : 9;
    ll res = 0;
    for (int i = 0; i <= up; i++){
        if (lead || abs(i - pre) >= 2){
            res += dfs(pos - 1, i, limit && (i == up), lead && (i == 0));
        }
    }
    if (!limit && !lead) dp[pos][pre] = res;
    return res;
}

ll solve(ll x){
    int len = 0;
    while (x){
        digit[++len] = x % 10;
        x /= 10;
    }
    memset(dp, -1, sizeof(dp));
    return dfs(len, 0, true, true);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a, b;
    cin >> a >> b;
    cout << solve(b) - solve(a - 1) << endl;
    return 0;
}


