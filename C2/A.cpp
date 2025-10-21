#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll comb(int n) {
    ll res = 1;
    for (int i = 1; i <= n; ++i) {
        res = res * (2 * n - i + 1) / i;
    }
    return res;
}



int main() {
    int n;
    cin >> n;
    cout << comb(n) / (n + 1) << endl;
    return 0;
}