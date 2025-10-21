#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    ll min_val = LLONG_MAX, max_val = LLONG_MIN;
    ll min_cnt = 0, max_cnt = 0;
    
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        
        if (x < min_val) {
            min_val = x;
            min_cnt = 1;
        } else if (x == min_val) {
            min_cnt++;
        }
        
        if (x > max_val) {
            max_val = x;
            max_cnt = 1;
        } else if (x == max_val) {
            max_cnt++;
        }
    }
    
    ll max_diff = max_val - min_val;
    ll ways = (max_diff == 0) ? (ll)n * (n - 1) / 2 : min_cnt * max_cnt;
    
    cout << max_diff << " " << ways << endl;
    
    return 0;
}