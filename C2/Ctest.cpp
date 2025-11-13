#include <stdio.h>
#include <stdlib.h>

int heap[200007];
int ans[200007];
int cnt = 0;
void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void siftDown(int pos){
    int tmp = pos;
    while (tmp * 2 + 1 < cnt){
        int left = heap[tmp * 2 + 1];
        int right = tmp * 2 + 2 < cnt ? heap[tmp * 2 + 2] : 0;
        int maxchild = left > right ? tmp * 2 + 1 : tmp * 2 + 2;
        if (heap[tmp] < heap[maxchild]){
            swap(&heap[tmp], &heap[maxchild]);
            tmp = maxchild;
        }
        else break;
    }
}
void build(){
    for (int i = cnt / 2 - 1; i >= 0; i--){
        siftDown(i);
    }
}

int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++) scanf("%d", heap + i);
    cnt = n;
    build();
    for (int i = 0; i < q; i++){
        swap(&heap[0], &heap[cnt - 1]);
        cnt--;
        siftDown(0);
    }
    for (int i = 0; i < n; i++) printf("%d ", heap[i]);
    printf("\n");
    while (cnt){
        swap(&heap[0], &heap[cnt - 1]);
        cnt--;
        siftDown(0); 
    }
    for (int i = 0; i < n; i++) printf("%d ", heap[i]); 
    return 0;
}