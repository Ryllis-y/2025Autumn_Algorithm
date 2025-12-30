#include <bits/stdc++.h>
using namespace std;
const int maxn = 11000007;
char s[maxn], str[maxn << 1];
int p[maxn << 1];

int manacher(){
    int len = strlen(s);
    str[0] = '$';
    str[1] = '#';
    int cnt = 2;
    for (int i = 0; i < len; i++){
        str[cnt++] = s[i];
        str[cnt++] = '#';
    }
    str[cnt] = '\0';
    int mx = 0, id = 0, ans = 0;
    for (int i = 1; i < cnt; i++){
        if (i < mx){
            p[i] = min(p[2 * id - i], mx - i);
        }
        else {
            p[i] = 1;
        }
        while (str[i + p[i]] == str[i - p[i]]){
            p[i]++;
        }
        if (mx < i + p[i]){
            mx = i + p[i];
            id = i;
        }
        ans = max(ans, p[i] - 1);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    cout << manacher() << endl;
    return 0;
}


