#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
pair<int, int> arr[1000007];
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i].second >> arr[i].first;
    }
    sort(arr, arr + n);

    int cur = 0, ans = 0;
    for (int i = 0; i < n; i++){
        if (arr[i].second >= cur){
            cur = arr[i].first;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}