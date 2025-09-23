#include <bits/stdc++.h>
using namespace std;
const int mod = 10007;
long long ans[300];
long long sum = 0;
typedef long long ll;
long long fastPower(long long base, long long exponent) {
    ll result = 1;
    while (exponent > 0) {
        if (exponent & 1) {  
            result *= base;
        }
        base *= base;       // 底数平方
        exponent >>= 1;     // 指数减半
    }
    return result;
}
int main(){
    ll n;
    cin >> n;
    ll* arr = new ll[n];
    ll x, m,a;
    for (ll i = 0; i < n; i++){
        memset(ans,0,sizeof(ll));
        cin >> x >> m;
        ll *tmp = new ll[m];
        for (ll i = 0; i < m; i++){
            cin >> a;
            ans[i] += a * fastPower(x, i);
            ans[i] %= mod;
        }
        for (int i = 0; i < m; i++){
            sum += ans[i];
            sum %= mod;
        }
        cout << sum << endl;
    }
    
    return 0;

}