#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int cnt = 0, increase_cnt = 0, decrease_cnt = 0;
ll increase[100007], decrease[100007], arr[100007];
int bisearch_le(int l, int r, ll target){  //找到第一个大于等于目标的位置
    int mid = (l + r) >> 1;
    while (l <= r){
        if (increase[mid] >= target){
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
        mid = (l + r) >> 1;
    }
    return l;
}
int bisearch_gt(int l, int r, ll target){ //找到第一个严格比目标小的位置
    int mid = (l + r) >> 1;
    while (l <= r){
        if (decrease[mid] < target){
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
        mid = (l + r) >> 1;
    }
    return l;
}
int main(){
    ll num;
    while(~scanf("%lld", &num)){
        arr[cnt++] = num;
        int de = bisearch_gt(0, decrease_cnt - 1, num);
        int in = bisearch_le(0, increase_cnt - 1, num);
        if (de == decrease_cnt){
            decrease[decrease_cnt++] = num;
        }
        else {
            decrease[de] = num;
        }
        if (in == increase_cnt){
            increase[increase_cnt++] = num;
        }
        else {
            increase[in] = num;
        }
    }
    cout << decrease_cnt << endl << increase_cnt << endl;
    return 0;
}