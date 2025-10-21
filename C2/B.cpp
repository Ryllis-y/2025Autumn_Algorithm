#include <stdio.h>
#include <stdlib.h>
#include <limits.h>  

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int *arr = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", arr + i);
        }
        
        int max1 = INT_MIN, max2 = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (arr[i] > max1) {
                max2 = max1;
                max1 = arr[i];
            } else if (arr[i] > max2) {
                max2 = arr[i];
            }
        }
        
        printf("%d\n", max1 + max2);
        free(arr);
    }
    return 0;
}
