#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<int, int> mp;
    int num;
    for (int i = 0; i < n; i++){
        cin >> num;
        if (++mp[num] > (n >> 1)){
            cout << num << endl;
            return 0;
        }
    }

    return 0;
}