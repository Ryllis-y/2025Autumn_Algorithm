#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2005;
int prev_row[MAXN], curr_row[MAXN];
string a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        int lena = a.length();
        int lenb = b.length();

        memset(prev_row, 0, sizeof(prev_row));
        memset(curr_row, 0, sizeof(curr_row));
        
        int ans1 = 0;  
        ll lcs2 = 0; 
        
        for (int i = 1; i <= lena; ++i) {
            for (int j = 1; j <= lenb; ++j) {
                if (a[i-1] == b[j-1]) {
                    curr_row[j] = prev_row[j-1] + 1;
                    ans1 = max(ans1, curr_row[j]);
                    lcs2 = curr_row[j];
                } else {
                    curr_row[j] = 0;
                    lcs2 = max(prev_row[j], curr_row[j-1]);
                }
                prev_row[j] = lcs2;  
            }
            swap(prev_row, curr_row);
            memset(curr_row, 0, sizeof(curr_row));
        }
        
        cout << ans1 << " " << prev_row[lenb] << "\n";
    }
    return 0;
}