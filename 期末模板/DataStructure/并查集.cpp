#include <bits/stdc++.h>
using namespace std;

int* arr;
void build(int n){
    for (int i = 0; i < n; i++){
        arr[i] = i;
    }
}
int find(int x){
    if (arr[x] != x){
        arr[x] = find(arr[x]);
    }
    return arr[x];
}
void merge(int a, int b){
    int fa = find(a);
    int fb = find(b);
    if (fa != fb){
        arr[fa] = fb;
    }
}
bool same(int a, int b){
    int fa = find(a);
    int fb = find(b);
    return fa == fb;
}


int main(){
    int n, m;
    cin >> n >> m;
    arr = new int[n];
    build(n);
    int op, a, b;
    for (int i = 0; i < m; i++){
        cin >> op >> a >> b;
        if (op == 1){
            merge(a - 1, b - 1);
        }
        else{
            if (same(a - 1, b - 1)){
                cout << "Y" << endl;
            }
            else{
                cout << "N" << endl;
            }
        }
    }    

    delete[] arr;
    return 0;
}