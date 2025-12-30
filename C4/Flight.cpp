#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll cb2(ll n) {
    if (n < 2) return 0;
    return n * (n - 1) / 2;
}
bool check(ll k, ll S, ll M) {
    if (k == 0) return M == 0;
    ll num = k + 1;
    ll size = S / num;
    ll leftSum = (S % num) * cb2(size + 1) + (num - S % num) * cb2(size);
    return cb2(S) - leftSum >= M;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll S, M;
    cin >> S >> M;
    if (M > cb2(S)) {
        cout << -1 << endl;
        return 0;
    }
    ll l = 0, r = S - 1, ans = -1;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (check(mid, S, M)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}
