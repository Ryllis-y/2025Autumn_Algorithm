#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<string,int>mp;
    string* arr = new string[n];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
        mp[arr[i]]++;
    }
    for (auto i : mp){
        if (i.second == 5){
            cout << i.first << endl;
            return 0;
        }
    }
    return 0;
}