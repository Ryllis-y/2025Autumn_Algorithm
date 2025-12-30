#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[10007], price[10007], pre[10007];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> price[i];
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            if (dp[i] < dp[i - j] + price[j]){
                dp[i] = dp[i - j] + price[j];
                pre[i] = j;
            }
        }
    }
    cout << dp[n] << endl;
    int len = n;
    vector<int> ans;
    while (pre[len]){
        ans.push_back(pre[len]);
        len -= pre[len];
    }
    cout << ans.size() << endl;
    for (auto x : ans){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}