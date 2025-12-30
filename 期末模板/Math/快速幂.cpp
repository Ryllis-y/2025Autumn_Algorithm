#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll qpow(ll a, ll b, ll mod){
    ll res = 1;
    while (b){
        if (b & 1){
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a, b, p;
    cin >> a >> b >> p;
    cout << a << "^" << b << " mod " << p << "=" << qpow(a, b, p) << endl;
    return 0;
}
