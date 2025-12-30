#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;     
        ll p = -1;
        for (ll i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                p = i;
                break;
            }
        }
        if (p == -1) {
            cout << "NO" << endl;
            continue;
        }
        
        ll tmp = n;
        while (tmp % p == 0) {
            tmp /= p;
        }

        cout << (tmp > 1 ? "YES" : "NO") << endl;
    }
    
    return 0;
}