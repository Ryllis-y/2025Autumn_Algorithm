#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100007;
ll arr[maxn], tree[maxn << 2], lazy[maxn << 2];

void pushup(int rt){
    tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
}

void pushdown(int rt, int l, int r){
    if (lazy[rt]){
        int mid = (l + r) >> 1;
        lazy[rt << 1] += lazy[rt];
        lazy[rt << 1 | 1] += lazy[rt];
        tree[rt << 1] += lazy[rt] * (mid - l + 1);
        tree[rt << 1 | 1] += lazy[rt] * (r - mid);
        lazy[rt] = 0;
    }
}

void build(int rt, int l, int r){
    if (l == r){
        tree[rt] = arr[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}

void update(int rt, int l, int r, int L, int R, ll val){
    if (L <= l && r <= R){
        tree[rt] += val * (r - l + 1);
        lazy[rt] += val;
        return;
    }
    pushdown(rt, l, r);
    int mid = (l + r) >> 1;
    if (L <= mid) update(rt << 1, l, mid, L, R, val);
    if (R > mid) update(rt << 1 | 1, mid + 1, r, L, R, val);
    pushup(rt);
}

ll query(int rt, int l, int r, int L, int R){
    if (L <= l && r <= R){
        return tree[rt];
    }
    pushdown(rt, l, r);
    int mid = (l + r) >> 1;
    ll sum = 0;
    if (L <= mid) sum += query(rt << 1, l, mid, L, R);
    if (R > mid) sum += query(rt << 1 | 1, mid + 1, r, L, R);
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    build(1, 1, n);
    while (m--){
        int op, l, r;
        ll val;
        cin >> op;
        if (op == 1){
            cin >> l >> r >> val;
            update(1, 1, n, l, r, val);
        }
        else {
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << endl;
        }
    }
    return 0;
}

