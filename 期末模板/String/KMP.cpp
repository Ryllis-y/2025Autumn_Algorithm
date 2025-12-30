#include <bits/stdc++.h>
using namespace std;

int nxt[1000007];
vector<int> ans;
void getNxt(string s){
    int len = s.length();
    nxt[0] = -1;
    nxt[1] = 0;
    int i = 2, cn = 0;
    while (i <= len){
        if (s[i - 1] == s[cn]){
            nxt[i++] = ++cn;
        }
        else if (cn > 0){
            cn = nxt[cn];
        }
        else {
            nxt[i++] = 0;
        }
    }
}

int kmp(string s1, string s2){
    getNxt(s2);
    int len1 = s1.length(), len2 = s2.length(), x = 0, y = 0;
    while (x < len1 && y < len2){
        if (s1[x] == s2[y]){
            x++;
            y++;
        }
        else if (y == 0){
            x++;
        }
        else {
            y = nxt[y];
        }
        if (y == len2) {
            cout << x - y + 1 << endl;  
            y = nxt[y];  
        }
    }
    return y == len2 ? x - y : -1;
}
int main(){
    string s1, s2;
    cin >> s1 >> s2;
    int len2 = s2.length(), len1 = s1.length();
    kmp(s1, s2);
    for (int i = 1; i <= len2; i++){
        cout << nxt[i] << " ";
    }
}