#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int lcs1[2001][2001], lcs2[2001][2001];
string a, b;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        memset(lcs1, 0, sizeof(lcs1));
        memset(lcs2, 0, sizeof(lcs1));
        cin >> a >> b;
        int lena = a.length();
        int lenb = b.length();
        int ans1 = 0;
        for (int i = 1; i <= lena; i++){
            for (int j = 1; j<= lenb; j++){
                if (a[i - 1] == b[j - 1]){
                    lcs2[i][j] = lcs2[i - 1][j - 1] + 1;
                    lcs1[i][j] = lcs1[i - 1][j - 1] + 1;
                }
                else{
                    lcs2[i][j] = max(max(lcs2[i - 1][j], lcs2[i][j - 1]), lcs2[i - 1][j - 1]);
                    lcs1[i][j] = 0;
                }
                ans1 = max(ans1, lcs1[i][j]);
            }
        }
        cout << ans1 << " " << lcs2[lena][lenb] << endl;

    }
    return 0;
}