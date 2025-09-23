#include <bits/stdc++.h>


using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    // 前缀GCD
    vector<long long> prefix(n);
    prefix[0] = a[0];
    for (int i = 1; i < n; ++i) {
        prefix[i] = gcd(prefix[i-1], a[i]);
    }

    // 后缀GCD
    vector<long long> suffix(n);
    suffix[n-1] = a[n-1];
    for (int i = n-2; i >= 0; --i) {
        suffix[i] = gcd(suffix[i+1], a[i]);
    }

    vector<long long> res(n);
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            res[i] = suffix[1];
        } else if (i == n-1) {
            res[i] = prefix[n-2];
        } else {
            res[i] = gcd(prefix[i-1], suffix[i+1]);
        }
    }

    for (long long x : res) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
