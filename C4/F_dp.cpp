#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int S, M;
    cin >> S >> M;
    
    ll max_total = (ll)S * (S - 1) / 2;
    if (M > max_total) {
        cout << -1 << endl;
        return 0;
    }
    if (M == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    for (int t = 2; t <= S; t++) {
        ll k = t - 1; 
        ll q = S / t;
        ll r = S % t;
        ll sum_sq = r * q * (q + 1) / 2 + (t - r) * q * (q - 1) / 2;
        ll happiness = max_total - sum_sq;
        if (happiness >= M) {
            cout << k << endl;
            return 0;
        }
    }
    
    cout << -1 << endl;
    return 0;
}