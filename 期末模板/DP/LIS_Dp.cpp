#include <bits/stdc++.h>
using namespace std;

int dp[1007];
int arr[1007];
int ans = 0;
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++){
        dp[i] = 1;
        for (int j = 0; j < i; j++){
            if (arr[j] >= arr[i]){
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;

}