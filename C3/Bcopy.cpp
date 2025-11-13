#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[10007], p[10007];   
int prev_[10007];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = p[i-1]; 
        prev_[i] = i;   
        for (int j = 1; j < i; j++) {  //枚举钢管 重量即为编号
            if (dp[i-j] + p[j-1] > dp[i]) {
                dp[i] = dp[i-j] + p[j-1];
                prev_[i] = j; 
            }
        }
    }


    vector<int> ans;
    int len = n;
    while (len > 0) {
        ans.push_back(prev_[len]);
        len -= prev_[len];
    }

    cout << dp[n] << "\n";
    cout << ans.size() << "\n";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}