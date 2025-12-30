#include <bits/stdc++.h>
using namespace std;

const int MAXN = 405;

// ==================== 匈牙利算法（正确解法） ====================
int n;
int a[MAXN], p[MAXN], b[MAXN], q[MAXN];
int graph[MAXN][MAXN];
int match[MAXN];
bool visited[MAXN];

bool canMatch(int i, int j) {
    return (a[i] >= q[j] && b[j] >= p[i]);
}

bool dfs(int u) {
    for (int v = 0; v < n; v++) {
        if (graph[u][v] && !visited[v]) {
            visited[v] = true;
            if (match[v] == -1 || dfs(match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int hungarian() {
    memset(match, -1, sizeof(match));
    int cnt = 0;
    
    for (int u = 0; u < n; u++) {
        memset(visited, false, sizeof(visited));
        if (dfs(u)) {
            cnt++;
        }
    }
    return cnt;
}

int solve_hungarian() {
    // 构建二分图
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = canMatch(i, j) ? 1 : 0;
        }
    }
    return hungarian();
}

// ==================== 贪心算法（待验证） ====================
struct Toby {
    int a, p, id;
};

struct Mogy {
    int b, q, id;
};

int solve_greedy() {
    vector<Toby> tobies(n);
    vector<Mogy> mogies(n);
    
    for (int i = 0; i < n; i++) {
        tobies[i] = {a[i], p[i], i};
        mogies[i] = {b[i], q[i], i};
    }

    sort(tobies.begin(), tobies.end(), [](const Toby& x, const Toby& y) {
        return x.a > y.a;
    });

    sort(mogies.begin(), mogies.end(), [](const Mogy& x, const Mogy& y) {
        return x.b > y.b;
    });
    
    multiset<pair<int, int>> available; // 存储 (q, id)
    int ans = 0;
    int j = 0; 
    
    for (int i = 0; i < n; i++) {
        while (j < n && mogies[j].b >= tobies[i].p) {
            available.insert({mogies[j].q, mogies[j].id});
            j++;
        }
        auto it = available.lower_bound({tobies[i].a + 1, -1});
        if (it != available.begin()) {
            it--;
            available.erase(it);
            ans++;
        }
    }
    
    return ans;
}

// ==================== 随机数据生成器 ====================
void generate_test(int test_id) {
    // 设置不同的随机种子
    mt19937 rng(test_id + time(0));
    uniform_int_distribution<int> dist(0, 1000);
    
    n = 10 + test_id % 10; // 测试数据规模逐渐增大
    
    for (int i = 0; i < n; i++) {
        a[i] = dist(rng);
        p[i] = dist(rng);
        b[i] = dist(rng);
        q[i] = dist(rng);
    }
}

// ==================== 手动测试用例 ====================
void manual_test_1() {
    n = 3;
    // Toby: (a, p)
    a[0] = 10, p[0] = 5;
    a[1] = 8, p[1] = 6; 
    a[2] = 6, p[2] = 4;
    
    // Mogy: (b, q)
    b[0] = 7, q[0] = 9;
    b[1] = 6, q[1] = 7;
    b[2] = 5, q[2] = 5;
}

void manual_test_2() {
    n = 4;
    // 所有Toby要求都很高，但墨鱼魅力值不够
    a[0] = 100, p[0] = 90;
    a[1] = 95, p[1] = 85;
    a[2] = 90, p[2] = 80;
    a[3] = 85, p[3] = 75;
    
    b[0] = 80, q[0] = 95;
    b[1] = 85, q[1] = 90;
    b[2] = 70, q[2] = 85;
    b[3] = 75, q[3] = 80;
}

void manual_test_3() {
    n = 3;
    // 完全匹配的情况
    a[0] = 10, p[0] = 1;
    a[1] = 20, p[1] = 2;
    a[2] = 30, p[2] = 3;
    
    b[0] = 10, q[0] = 1;
    b[1] = 20, q[1] = 2;
    b[2] = 30, q[2] = 3;
}

// ==================== 主函数 ====================
int main() {
    int total_tests = 0, passed_tests = 0;
    
    cout << "=== 开始对数器测试 ===" << endl;
    
    // 测试手动用例
    vector<void(*)()> manual_tests = {manual_test_1, manual_test_2, manual_test_3};
    
    for (int i = 0; i < manual_tests.size(); i++) {
        cout << "手动测试用例 " << i + 1 << ": ";
        manual_tests[i]();
        
        int ans_greedy = solve_greedy();
        int ans_hungarian = solve_hungarian();
        
        cout << "贪心 = " << ans_greedy << ", 匈牙利 = " << ans_hungarian;
        if (ans_greedy == ans_hungarian) {
            cout << " ✓ 通过" << endl;
            passed_tests++;
        } else {
            cout << " ✗ 失败" << endl;
            // 输出详细信息用于调试
            cout << "   Toby数据: ";
            for (int j = 0; j < n; j++) cout << "(" << a[j] << "," << p[j] << ") ";
            cout << endl << "   Mogy数据: ";
            for (int j = 0; j < n; j++) cout << "(" << b[j] << "," << q[j] << ") ";
            cout << endl;
        }
        total_tests++;
    }
    
    // 测试随机用例
    cout << "随机测试用例: " << endl;
    for (int i = 0; i < 20; i++) {
        generate_test(i);
        
        int ans_greedy = solve_greedy();
        int ans_hungarian = solve_hungarian();
        
        if (ans_greedy == ans_hungarian) {
            cout << "测试 " << i + 1 << ": ✓ (n=" << n << ", 匹配数=" << ans_greedy << ")" << endl;
            passed_tests++;
        } else {
            cout << "测试 " << i + 1 << ": ✗ 贪心=" << ans_greedy << " 匈牙利=" << ans_hungarian << endl;
        }
        total_tests++;
    }
    
    cout << "=== 测试结果 ===" << endl;
    cout << "总计: " << total_tests << " 个测试用例" << endl;
    cout << "通过: " << passed_tests << " 个" << endl;
    cout << "失败: " << total_tests - passed_tests << " 个" << endl;
    cout << "通过率: " << fixed << setprecision(2) << (passed_tests * 100.0 / total_tests) << "%" << endl;
    
    if (passed_tests == total_tests) {
        cout << "🎉 贪心算法正确！" << endl;
    } else {
        cout << "❌ 贪心算法有误，需要调试" << endl;
    }
    
    return 0;
}