#include <bits/stdc++.h>
using namespace std;
int A[20007], B[20007];
int ans[100007];
int main(){
    int t;
    string a, b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        int al = a.size(), bl = b.size(), carry = 0;
        
        for (int i = al - 1; i >= 0; i--){
            A[al - 1 - i] = a[i] - '0';
        }
        for (int i = bl - 1; i >= 0; i--){
            B[bl - 1 - i] = b[i] - '0';
        }
        memset(ans, 0, sizeof(ans));
        for (int i = 0; i < al; i++){
            carry = 0;
            for (int j = 0; j < bl; j++){
                ans[i + j] += A[i] * B[j] + carry;
                carry = ans[i + j] / 10;
                ans[i + j] %= 10;
            }
            ans[i + bl] += carry;
        }
        bool flag = false;
        for (int i = al + bl - 1; i >= 0; i--){
            if (flag == false && ans[i] == 0){
                continue;
            }
            flag = true;
            cout << ans[i];
        }
        if (flag == false) cout << 0;
        cout << endl;
    }
    return 0;
}