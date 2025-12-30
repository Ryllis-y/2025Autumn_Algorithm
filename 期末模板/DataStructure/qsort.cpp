#include <bits/stdc++.h>
using namespace std;

int arr[10007];

int partition1(int l, int r, int m){
    if (l >= r) return 0;
    int index = l;
    int xindex = 0;
    int a = l;
    for (index = l; index <= r; index++){
        if (arr[index] <= arr[m]){
            if (arr[index] == arr[m]){
                xindex = a;
            }
            swap(arr[index],arr[a]);
            a++;

        }
    }
    swap(arr[xindex],arr[a - 1]);
    return a - 1;
}

int quicksort1(int l, int r){
    if (l >= r) return 0;
    int x = l + random() % (r - l + 1);
    int neopos = partition1(l, r, x);
    quicksort1(l,neopos - 1);
    quicksort1(neopos + 1, r);
    return 0;
}

int main(){
    int num;
    cin >> num;
    for (int i = 0; i < num; i++){
        cin >> arr[i];
    }
    quicksort1(0,num - 1);
    for (int i = 0; i < num; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;

}