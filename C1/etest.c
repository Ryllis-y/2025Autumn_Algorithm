#include <stdio.h>
#include <stdlib.h>

// 链表节点结构
typedef struct Node {
    long long co;    // 系数
    long long exp;   // 指数
    struct Node* next;
} Node;

// 创建新节点
Node* createNode(long long co, long long exp) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->co = co;
    node->exp = exp;
    node->next = NULL;
    return node;
}

// 释放链表
void freeList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        // 读取第一个多项式
        scanf("%d", &n);
        long long* a = (long long*)malloc(n * sizeof(long long));
        long long* A = (long long*)malloc(n * sizeof(long long));
        for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
        for (int i = 0; i < n; ++i) scanf("%lld", &A[i]);
        
        // 读取第二个多项式
        scanf("%d", &m);
        long long* b = (long long*)malloc(m * sizeof(long long));
        long long* B = (long long*)malloc(m * sizeof(long long));
        for (int i = 0; i < m; ++i) scanf("%lld", &b[i]);
        for (int i = 0; i < m; ++i) scanf("%lld", &B[i]);
        
        // 链表头节点和尾指针（尾插法高效插入）
        Node* head = NULL;
        Node* tail = NULL;
        int i = 0, j = 0;  // 双指针
        
        // 双指针合并
        while (i < n && j < m) {
            Node* newNode;
            if (A[i] < B[j]) {
                newNode = createNode(a[i], A[i]);
                i++;
            } else if (A[i] > B[j]) {
                newNode = createNode(b[j], B[j]);
                j++;
            } else {
                newNode = createNode(a[i] + b[j], A[i]);
                i++;
                j++;
            }
            // 尾插法加入链表
            if (!head) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        
        // 处理剩余项（第一个多项式）
        while (i < n) {
            Node* newNode = createNode(a[i], A[i]);
            tail->next = newNode;
            tail = newNode;
            i++;
        }
        // 处理剩余项（第二个多项式）
        while (j < m) {
            Node* newNode = createNode(b[j], B[j]);
            tail->next = newNode;
            tail = newNode;
            j++;
        }
        
        // 统计项数k并输出
        int k = 0;
        Node* curr = head;
        // 第一次遍历：计算k并输出系数
        //printf("%d\n", k);  // 先占位，后续会重新计算
        curr = head;
        while (curr) {
            k++;
            curr = curr->next;
        }
        printf("%d\n", k);  // 输出正确的k
        
        // 输出系数
        curr = head;
        while (curr) {
            printf("%lld ", curr->co);
            curr = curr->next;
        }
        printf("\n");
        
        // 输出指数
        curr = head;
        while (curr) {
            printf("%lld ", curr->exp);
            curr = curr->next;
        }
        printf("\n");
        
        // 释放资源
        free(a); free(A); free(b); free(B);
        freeList(head);
    }
    return 0;
}