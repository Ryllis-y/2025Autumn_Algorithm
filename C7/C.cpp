#include <bits/stdc++.h>
using namespace std;
int nxt[10007];
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
    //getNxt(s2);
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
        // if (y == len2) {
        //     //cout << x - y + 1 << endl;  
        //     y = nxt[y];  
        // }
    }
    return y == len2 ? x - y : -1;
}
int main(){
    string line, b = "cactus";
    int cnt = 0;
    getNxt(b);
    while (getline(cin, line)){
        for (int i = 0; line[i]; i++) if (isupper(line[i])) line[i] = tolower(line[i]);
        int len = line.length();
        int flag = 0;
        for (int i = 0; line[i]; i++){
            if (i + 2 < len && line[i] == 'c' && line[i+1] == 'a' && line[i+2] == 'c'){
                if (i == 0 || line[i - 1] == ' ') {
                    cnt++;
                    flag = 1;
                    break;
                } 
            }
            else if (i + 2 < len && line[i] == 't' && line[i+1] == 'u' && line[i+2] == 's'){
                if (i + 3 == len || line[i+3] == ' '){
                    cnt++;
                    flag = 1;
                    break;
                }
            }
        }
        if (!flag){
            if (kmp(line, b) != -1) cnt++;
        }

    }
    cout << cnt << endl;
    return 0;
}