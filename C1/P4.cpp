#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> positions(m);
    string directions;
    
    for (int i = 0; i < m; i++) {
        cin >> positions[i];
    }
    cin >> directions;
    
    int first_fall_time = n + 1; 
    int last_fall_time = 0;
    for (int i = 0; i < m; i++) {
        if (directions[i] == 'L') {
            // 向左运动的蚂蚁：掉落到0位置的时间就是当前位置
            first_fall_time = min(first_fall_time, positions[i]);
            last_fall_time = max(last_fall_time, positions[i]);
        } else { // 'R'
            // 向右运动的蚂蚁：掉落到n+1位置的时间是(n+1 - position)
            int fall_time = n + 1 - positions[i];
            last_fall_time = max(last_fall_time, fall_time);
            // 对于第一只掉落的时间，向左运动的蚂蚁会更早掉落
        }
    }
    
    first_fall_time = n + 1;
    for (int i = 0; i < m; i++) {
        if (directions[i] == 'L') {
            first_fall_time = min(first_fall_time, positions[i]);
        }
    }
    
    if (first_fall_time == n + 1) {
        first_fall_time = n + 1;
        for (int i = 0; i < m; i++) {
            if (directions[i] == 'R') {
                first_fall_time = min(first_fall_time, n + 1 - positions[i]);
            }
        }
    }
    
    cout << first_fall_time << " " << last_fall_time << endl;
    
    return 0;
}