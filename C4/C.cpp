#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[100007], cost[1007], value[1007];

int main(){
    int n, v;
    cin >> n >> v;
    for (int i = 0; i < n; i++){
        cin >> cost[i] >> value[i];
    }
    for (int i = 1; i <= n; i++){
        for (int j = v; j >= cost[i - 1]; j--){
            dp[j] = max(dp[j], dp[j - cost[i - 1]] + value[i - 1]);
        }
    }
    cout << dp[v] << endl;
    return 0;
}