#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[10007], arr[10007], pre[10007];

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
        pre[i] = i;
        dp[i] = arr[i];
    }
    
    for (int i = 2; i <= n; i++){
        for (int j = 1; j < i; j++){
            if (dp[i-j] + arr[j] > dp[i]) {
                dp[i] = dp[i-j] + arr[j];
                pre[i] = j; 
            }
        }
    }
    vector<int> ans;
    int len = n;
    while (len){
        ans.push_back(pre[len]);
        len -= pre[len];
    }

    cout << dp[n] << "\n";
    cout << ans.size() << "\n";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}