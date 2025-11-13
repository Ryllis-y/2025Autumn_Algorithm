#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long ll;

// 你的贪心算法
int greedy(int s, ll m) {
    priority_queue<int> pq;
    pq.push(s);
    ll total = 0;
    ll cnt = 0;
    
    while (true) {
        if (pq.empty()) break;
        ll q = pq.top();
        pq.pop();
        if (q < 2) continue;
        
        ll a = q / 2;
        ll b = q - a;
        ll gain = a * b;
        total += gain;
        cnt++;
        
        if (total >= m) {
            return cnt;
        }
        
        pq.push(a);
        pq.push(b);
    }
    
    return -1;
}

// 数学公式法（假设为正确解法）
int math_solution(int s, ll m) {
    ll max_total = (ll)s * (s - 1) / 2;
    if (m > max_total) {
        return -1;
    }
    if (m == 0) {
        return 0;
    }
    
    for (int t = 2; t <= s; t++) {
        int k = t - 1;
        int q = s / t;
        int r = s % t;
        ll sum_sq = (ll)r * q * (q + 1) / 2 + (ll)(t - r) * q * (q - 1) / 2;
        ll happiness = max_total - sum_sq;
        if (happiness >= m) {
            return k;
        }
    }
    
    return -1;
}

// 暴力搜索（用于小数据验证）
int brute_force(int s, ll m, vector<int> groups, ll current_happiness, int steps, int& best) {
    if (current_happiness >= m) {
        if (best == -1 || steps < best) {
            best = steps;
        }
        return steps;
    }
    
    if (steps >= best && best != -1) {
        return best; // 剪枝
    }
    
    int n = groups.size();
    for (int i = 0; i < n; i++) {
        int q = groups[i];
        if (q < 2) continue;
        
        for (int a = 1; a < q; a++) {
            vector<int> new_groups = groups;
            new_groups.erase(new_groups.begin() + i);
            new_groups.push_back(a);
            new_groups.push_back(q - a);
            
            ll gain = (ll)a * (q - a);
            brute_force(s, m, new_groups, current_happiness + gain, steps + 1, best);
        }
    }
    
    return best;
}

int brute_wrapper(int s, ll m) {
    if (m == 0) return 0;
    ll max_total = (ll)s * (s - 1) / 2;
    if (m > max_total) return -1;
    
    int best = -1;
    vector<int> groups = {s};
    brute_force(s, m, groups, 0, 0, best);
    return best;
}

// 随机测试
void random_test() {
    srand(time(0));
    
    int test_count = 1000;
    for (int test = 1; test <= test_count; test++) {
        int s = rand() % 20 + 2;  // S从2到21
        ll max_possible = (ll)s * (s - 1) / 2;
        ll m = rand() % (max_possible + 1) + 1;
        
        int ans1 = greedy(s, m);
        int ans2 = math_solution(s, m);
        
        // 对于小数据，用暴力验证
        int ans3 = -2;
        if (s <= 12) {
            ans3 = brute_wrapper(s, m);
        }
        
        if (ans1 != ans2) {
            cout << "发现不一致！S=" << s << ", M=" << m << endl;
            cout << "贪心结果: " << ans1 << endl;
            cout << "数学结果: " << ans2 << endl;
            if (ans3 != -2) {
                cout << "暴力结果: " << ans3 << endl;
            }
            cout << "最大可能快乐值: " << max_possible << endl;
            cout << "---" << endl;
            
            // 验证这个用例
            if (ans3 != -2 && ans1 != ans3) {
                cout << "!!! 贪心结果与暴力结果不一致 !!!" << endl;
                return;
            }
        }
    }
    cout << "随机测试完成，未发现不一致" << endl;
}

// 特定测试用例
void specific_test() {
    vector<pair<int, ll>> tests = {
        {6, 8}, {7, 11}, {8, 15}, {9, 20}, {10, 24},
        {4, 5}, {5, 9}, {6, 12}, {7, 15}, {8, 18}
    };
    
    for (auto [s, m] : tests) {
        int ans1 = greedy(s, m);
        int ans2 = math_solution(s, m);
        int ans3 = -2;
        if (s <= 12) {
            ans3 = brute_wrapper(s, m);
        }
        
        cout << "S=" << s << ", M=" << m << ": 贪心=" << ans1 << ", 数学=" << ans2;
        if (ans3 != -2) {
            cout << ", 暴力=" << ans3;
        }
        cout << endl;
        
        if (ans1 != ans2) {
            cout << "!!! 不一致 !!!" << endl;
        }
    }
}

int main() {
    cout << "开始特定测试..." << endl;
    specific_test();
    
    cout << "\n开始随机测试..." << endl;
    random_test();
    
    return 0;
}