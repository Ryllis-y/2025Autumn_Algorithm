#include <stdio.h>
#include <stdlib.h>

int heap[100007];
int cnt = 0;
void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void siftUp(int pos){
    int cur = pos;
    while (cur > 0){
        int parent = (cur - 1) >> 1;
        if (heap[parent] < heap[cur]){
            swap(&heap[parent], &heap[cur]);
            cur = parent;
        }
        else break;
    }
}
 void siftDown(int pos){
    int cur = pos;
    int child;
    while(cur * 2 + 1 < cnt){
        if (cur * 2 + 2 < cnt){
            child = heap[cur * 2 + 1] > heap[cur * 2 + 2] ? 
            cur * 2 + 1 : cur * 2 + 2;
        }
        else child = cur * 2 + 1;
        if (heap[cur] < heap[child]){
            swap(&heap[cur], &heap[child]);
            cur = child;
        }
        else break;
    }
 }
 void push(int value){
    heap[cnt++] = value;
    siftUp(cnt - 1);
 }
 int peak(){
    printf("%d\n", heap[0]);
    return heap[0];
 }
 int pop(){
    int tmp = heap[0];
    heap[0] = heap[--cnt];
    siftDown(0);
    return tmp;
 }
 int main(){
    int n;
    scanf("%d", &n);
    int op, value;
    for (int i = 0; i < n; i++){
        scanf("%d", &op);
        if (op == 1){
            scanf("%d", &value);
            push(value);
        }
        else if (op == 2){
            pop();
        }
        else if (op == 3){
            peak();
        }
    }
    while(cnt){
        printf("%d ",pop());
    }
    return 0;
 }