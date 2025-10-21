#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, * arr;
ll ind[200007];
ll pre[200007];
ll suf[200007];
ll f(ll l, ll r, ll k, ll less_cnt, ll greater_cnt){
    if (ind[k] < l || ind[k] > r) return -1;
    if (l > r) return -1;
    ll mid = (l + r) >> 1;
    if (arr[mid] == k) return llabs(less_cnt - greater_cnt) + less_cnt + greater_cnt;
    if (arr[mid] < k){
        if (ind[k] > mid){
            pre[k]--;
            return f(mid + 1, r, k, less_cnt, greater_cnt);
        }
        else {
            if (--suf[k] < 0) return -1;
            return f(l, mid - 1, k, less_cnt, greater_cnt + 1);
        }
        
    }
    else if (arr[mid] > k){
        if (ind[k] > mid){
            if (--pre[k] < 0) return -1;
            return f(mid + 1, r, k, less_cnt + 1, greater_cnt);
        }
        else {
            suf[k]--;
            return f(l, mid - 1, k, less_cnt, greater_cnt);
        }
    }
}

int main(){
    ll q, l, r, k;
    cin >> n >> q;
    arr = new ll[n + 1];
    for (ll i = 1; i <= n; i++){
        cin >> arr[i];
        ind[arr[i]] = i;
        pre[i] = i - 1;
        suf[i] = n - i;
    }

    while(q--){

        cin >> l >> r >> k;
        cout << f(l, r, k, 0, 0) << endl;
        //cout << pre[1] << suf[1] << endl;
        pre[k] = k - 1;
        suf[k] = n - k;
    }

    delete[] arr;
    return 0;
}