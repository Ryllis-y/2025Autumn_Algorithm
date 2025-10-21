#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    priority_queue<tuple<long long, int, int>, 
                   vector<tuple<long long, int, int>>, 
                   greater<>> pq; //小根堆

    // 划分为N个类 先让每个类中最小的元素入队
    for (int j = 0; j < N; j++) {
        pq.emplace(A[0] + B[j], 0, j);
    }

    vector<long long> result;
    for (int k = 0; k < N; k++) {
        auto [sum, i, j] = pq.top();
        pq.pop();
        result.push_back(sum);
        if (i + 1 < N) { //尝试让该类的下一个元素进队
            pq.emplace(A[i + 1] + B[j], i + 1, j);
        }
    }

    for (int k = 0; k < N; k++) {
        cout << result[k] << (k == N - 1 ? "\n" : " ");
    }

    return 0;
}