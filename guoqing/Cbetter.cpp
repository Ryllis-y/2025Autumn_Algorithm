#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 10007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
        a[i] %= MOD;
    }
    
    cin >> m;
    vector<int> b(m + 1);
    for (int i = 0; i <= m; i++) {
        cin >> b[i];
        b[i] %= MOD;
    }
    
    unordered_map<int, int> cache_a, cache_b;
    
    auto compute = [](const vector<int>& arr, int x, unordered_map<int, int>& cache) {
        if (cache.count(x)) return cache[x];
        int result = 0;
        for (int i = arr.size() - 1; i >= 0; i--) {
            result = (result * x + arr[i]) % MOD;
        }
        return cache[x] = result;
    };
    
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        int val_a = compute(a, x, cache_a);
        int val_b = compute(b, y, cache_b);
        cout << val_a * val_b % MOD << '\n';
    }
    
    return 0;
}