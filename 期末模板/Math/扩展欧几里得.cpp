#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll exgcd(ll a, ll b, ll &x, ll &y){
    if (b == 0){
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        ll a, b, c;
        cin >> a >> b >> c;
        ll x, y;
        ll d = exgcd(a, b, x, y);
        if (c % d != 0){
            cout << -1 << endl;
            continue;
        }
        x *= c / d;
        y *= c / d;
        ll dx = b / d, dy = a / d;
        ll xmin = (x % dx + dx) % dx;
        if (xmin == 0) xmin = dx;
        ll ymax = (c - a * xmin) / b;
        if (ymax <= 0){
            cout << xmin << " " << (y % dy + dy) % dy << endl;
        }
        else {
            ll ymin = (y % dy + dy) % dy;
            if (ymin == 0) ymin = dy;
            ll xmax = (c - b * ymin) / a;
            cout << (xmax - xmin) / dx + 1 << " " << xmin << " " << ymin << " " << xmax << " " << ymax << endl;
        }
    }
    return 0;
}


