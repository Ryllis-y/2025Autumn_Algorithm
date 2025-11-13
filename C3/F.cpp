#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[10005];
int s[10005];

int main() {
    int N, K;
    cin >> N >> K;
    for (int i = 1; i <= N; ++i) {
        cin >> s[i];
    }

    dp[0] = 0;
    
    for (int i = 1; i <= N; ++i) {
        int max_val = 0;
        for (int j = i; j >= 1 && j > i - K; --j) {
            max_val = max(max_val, s[j]);
            dp[i] = max(dp[i], dp[j - 1] + (ll)max_val * (i - j + 1));
        }
    }

    cout << dp[N] << endl;
    return 0;
}