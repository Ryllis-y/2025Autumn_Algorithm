#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 计算 C(n, 2) = n * (n - 1) / 2
ll cb2(ll n) {
    if (n < 2) {
        return 0;
    }
    return n * (n - 1) / 2;
}

// 检查 k 次操作是否能获得至少 M 的快乐值
bool check(ll k, ll S, ll M) {
    if (k == 0) {
        return M == 0;
    }
    // k 次操作会产生 k+1 个存钱罐
    ll num_piles = k + 1;
    
    // 将 S 个硬币尽可能平均地分到 num_piles 个存钱罐中
    ll base_size = S / num_piles;
    ll remainder = S % num_piles;

    // 有 remainder 个存钱罐的大小为 base_size + 1
    // 有 num_piles - remainder 个存钱罐的大小为 base_size

    // 计算最终状态下，还留在同一个存钱罐里的配对总数
    ll sum_of_remaining_pairs = remainder * cb2(base_size + 1) + (num_piles - remainder) * cb2(base_size);

    // 理论最大快乐值
    ll max_total_happiness = cb2(S);

    // k 次操作能达到的最大快乐值
    ll k_max_happiness = max_total_happiness - sum_of_remaining_pairs;

    return k_max_happiness >= M;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll S, M;
    cin >> S >> M;

    // 如果 M 大于理论最大值，则无解
    if (M > cb2(S)) {
        cout << -1 << endl;
        return 0;
    }

    // 二分答案
    ll l = 0, r = S - 1;
    ll ans = -1;

    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (check(mid, S, M)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}
