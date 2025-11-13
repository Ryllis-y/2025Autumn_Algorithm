#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll lcs2[2001][2001];    
ll lcs1[2001];          
string a, b;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        memset(lcs2, 0, sizeof(lcs2));
        memset(lcs1, 0, sizeof(lcs1));
        
        cin >> a >> b;
        int lena = a.length();
        int lenb = b.length();
        ll ans1 = 0;  
        
        for (int i = 1; i <= lena; i++){
            ll prev = lcs1[0];  
            for (int j = 1; j <= lenb; j++){
                ll temp = lcs1[j];  // 保存当前值，作为下一轮的左上角
                if (a[i - 1] == b[j - 1]){
                    lcs1[j] = prev + 1;
                    ans1 = max(ans1, lcs1[j]);
                } else {
                    lcs1[j] = 0;
                }
                prev = temp;  // 更新左上角为当前列的旧值

                if (a[i - 1] == b[j - 1]){
                    lcs2[i][j] = lcs2[i - 1][j - 1] + 1;
                } else {
                    lcs2[i][j] = max(max(lcs2[i - 1][j], lcs2[i][j - 1]), lcs2[i - 1][j - 1]);
                }
            }
           
        }
        
        cout << ans1 << " " << lcs2[lena][lenb] << endl;
    }
    return 0;
}