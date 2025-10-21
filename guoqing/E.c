#include <stdio.h>
#include <stdlib.h>
int n, q, v;
int* arr;
int lowerSearch(int target){
    int l = 0, r = n - 1;
    int mid;
    while (l <= r){
        mid = (l + r) >> 1;
        if (arr[mid] >= target){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return r + 2;
}
int upperSearch(int target){
    int l = 0, r = n - 1;
    int mid;
    while (l <= r){
        mid = (l + r) >> 1;
        if (arr[mid] > target){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return r + 2;
}
int main(){
    scanf("%d%d",&n, &q);
    arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++){
        scanf("%d",arr + i);
    }
    while(q--){
        scanf("%d", &v);
        printf("%d %d\n", lowerSearch(v), upperSearch(v));
    }

    free(arr);
    return 0;
}