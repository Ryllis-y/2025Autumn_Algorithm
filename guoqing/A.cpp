#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll qpow(ll base, ll exp) {
    ll result = 1;
    while (exp) {
        if (exp & 1) {
            result *= base;
        }
        base *= base;
        exp >>= 1;
    }
    return result;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //cout << (536870912 == qpow(2,29)) << endl; 
    ll t;
    cin >> t;
    ll a, b, k;
    
    for (int i = 0; i < t; i++){
        cin >> a >> b >> k;
        ll value = qpow(b, k);
        if (value == LONG_MAX){
            cout << "n^k"; 
        }
        else if (a > qpow(b, k)){
            cout << "n^{\\log_ba}";
        }
        else if (a == qpow(b, k)){
            cout << "n^k\\log n";
        }
        else{
            cout << "n^k";
        }
        cout << endl;
    }
    return 0;
}
/*
6
3 2 1
4 2 2
3 2 2
536870913 2 29
536870912 2 29
536870911 2 29
*/