#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll dp[107][53][2]; //pos n status 前i个位置 修改n次时 方向为正/反 规定初始为正(0)

int main(){
    cin >> s;
    int len = s.length();
    for (int i = 0; i < len; i++){
        if (s[i] == 'T'){
            dp[i + 1][0][0] = -dp[i][0][1];
            dp[i + 1][0][1] = -dp[i][0][0];
        }
        else {
            dp[i + 1][0][0] = dp[i][0][0] + 1;
            dp[i + 1][0][1] = dp[i][0][1] - 1;
            
        }
    }
    int n;
    cin >> n;
    for (int i = 1; i <= len; i++){
        for (int j = 1; j <= n; j++){
            if (s[i - 1] == 'T'){
                
            }
            else {

            }
        }
    }
}