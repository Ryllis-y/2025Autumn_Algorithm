#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000007;
int arr[maxn];

int bisearch_le(int l, int r, int target){
    int mid;
    while (l <= r){
        mid = (l + r) >> 1;
        if (arr[mid] >= target){
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return l;
}

int bisearch_gt(int l, int r, int target){
    int mid;
    while (l <= r){
        mid = (l + r) >> 1;
        if (arr[mid] > target){
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return l;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    while (m--){
        int x;
        cin >> x;
        int pos1 = bisearch_le(1, n, x);
        int pos2 = bisearch_gt(1, n, x);
        if (arr[pos1] == x){
            cout << pos1 << " " << pos2 - 1 << endl;
        }
        else {
            cout << -1 << " " << -1 << endl;
        }
    }
    return 0;
}


