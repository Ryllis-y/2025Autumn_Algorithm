#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll arr[100007];
ll help[100007];
ll n, k;
ll ans = 0;

void merge(ll l, ll m, ll r) {
    ll i = l, j = m + 1, cnt = l;
    
    ll ptr = l;  
    for (ll j = m + 1; j <= r; j++) {
        
        while (ptr <= m && arr[ptr] <= k * arr[j]) {
            ptr++;
        }
        ans += m - ptr + 1;
    }
    
    i = l, j = m + 1, cnt = l;
    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            help[cnt++] = arr[i++];
        } else {
            help[cnt++] = arr[j++];
        }
    }
    
    while (i <= m) help[cnt++] = arr[i++];
    while (j <= r) help[cnt++] = arr[j++];
    
    for (ll p = l; p <= r; p++) {
        arr[p] = help[p];
    }
}

void mergeSort(ll l, ll r) {
    if (l >= r) return;
    ll mid = (l + r) >> 1;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    merge(l, mid, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> k;
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    ans = 0;
    mergeSort(0, n - 1);
    
    cout << ans << endl;
    
    return 0;
}