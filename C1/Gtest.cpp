#include <bits/stdc++.h>
using namespace std;

int arr[50007];
int help[50007];
int num = 0;
long long ans = 0;
int mmsort(int l, int m, int r){
    int i = l, j = m + 1, cnt = l;
    while(i <= m && j <= r){
        if (arr[i] > arr[j]) ans += m - i + 1;
        help[cnt++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];

    }
    while (i <= m){
        help[cnt++] = arr[i++];
    }
    while (j <= r){
        help[cnt++] = arr[j++];
    }
    for (int k = l; k <= r; k++){
        arr[k] = help[k];
    }
    return 0;
}
int merges(int l, int r){
    if (l == r){
        return 0;
    }
    int mid = (l + r) >> 1;
    merges(l, mid);
    merges(mid + 1, r);
    mmsort(l, mid, r);
    return 0;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int k = 0; k < t; k++){
        cin >> num;
        ans = 0;
        for (int i = 0; i < num; i++){
            cin >> arr[i];
        }
        merges(0,num - 1);
        string name = ans % 2 == 1 ? "Bob": "Alice";
        cout << name << endl;
    }
    // int x;
    // cin >> num;
    // for (int i = 0; i < num; i++){
    //     cin >> arr[i];
    // }
    // merges(0,num - 1);
    // for (int i = 0; i < num; i++){
    //     cout << arr[i] << " ";
    // }

    cout << endl;
    return 0;
}