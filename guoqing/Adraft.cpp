#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll qpow(ll base, ll exp) {
    ll result = 1;
    while (exp > 0) {
        if (exp & 1) {
            if (result > LLONG_MAX / base) {
                return LLONG_MAX;  
            }
            result *= base;
        }
        if (exp > 1 && base > LLONG_MAX / base) {
            return LLONG_MAX;  
        }
        base *= base;
        exp >>= 1;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //cout << qpow(2, 29) << endl;
    ll t;
    cin >> t;
    ll a, b, k;
    
    for (int i = 0; i < t; i++) {
        cin >> a >> b >> k;
        
        ll power_val = qpow(b, k);
        
        if (power_val == LLONG_MAX) {
          
            cout << "n^k";
        } else if (a > power_val) {
            cout << "n^{\\log_ba}";
        } else if (a == power_val) {
            cout << "n^k\\log n";
        } else {
            cout << "n^k";
        }
        cout << endl;
    }
    return 0;
}