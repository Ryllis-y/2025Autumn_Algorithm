#include <iostream>
#include <vector>
#include <complex>
#include <cmath>

using namespace std;

// 使用 C++ 标准库的复数类型，cd 代表 complex double
using cd = complex<double>;
const double PI = acos(-1);
int offset = 0, cnt = 0;
/**
 * FFT 核心递归函数
 * @param a      系数数组（输入），变换后变为点值数组（输出）
 * @param invert false 表示 FFT（系数->点值），true 表示 IFFT（点值->系数）
 */
void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    
    // 1. 递归终止条件：当只有一个元素时，无需处理
    if (n == 1) return;

    // 2. 分治：将系数按下标奇偶分成两组
    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2 * i];     // 偶数位：a_0, a_2, ...
        a1[i] = a[2 * i + 1]; // 奇数位：a_1, a_3, ...
    }

    // 3. 递归：分别处理两半
    fft(a0, invert);
    fft(a1, invert);

    // 4. 合并：利用蝴蝶操作 (Butterfly Operation)
    // 准备单位根，ang 是角度。IFFT 时角度取反。
    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang)); // w 是当前旋转因子，wn 是步长

    for (int i = 0; 2 * i < n; i++) {
        // 蝴蝶操作核心公式：
        // A(x) = A_even(x^2) + x * A_odd(x^2)
        // 利用单位根的对称性，一次循环计算两个点：i 和 i + n/2
        
        a[i] = a0[i] + w * a1[i];           // 前一半
        a[i + n / 2] = a0[i] - w * a1[i];   // 后一半
        
        if (invert) {
            // IFFT 需要在合并时除以 2 (或者最后统一除以 n)
            // 这里选择在每层递归除以 2，最终效果等于除以 n
            a[i] /= 2;
            a[i + n / 2] /= 2;
        }
        
        w *= wn; // 旋转复数角度
    }
}

// 辅助函数：计算两个多项式的乘积
vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    // 1. 准备长度：结果长度为 n + m - 1，由于 FFT 需要 2 的幂次，所以我们要找到一个足够大的 2^k
    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;

    // 2. 转换成复数向量并补 0
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    fa.resize(n);
    fb.resize(n);

    // 3. FFT：系数 -> 点值
    fft(fa, false);
    fft(fb, false);

    // 4. 点值乘法：O(n)
    for (int i = 0; i < n; i++) {
        fa[i] *= fb[i];
    }

    // 5. IFFT：点值 -> 系数
    fft(fa, true);

    // 6. 整理结果：取实部并四舍五入
    vector<int> result(n);
    cnt = n;
    for (int i = 0; i < n; i++) {
        result[i] = round(fa[i].real());
        if (result[i] == 0) offset++;
        else offset = 0;
    }
    
    // 去掉可能存在的末尾多余的0，这里省略，视题目要求而定
    return result;
}

int main() {
    int n, m;

    cin >> n >> m;

    vector<int> a(n + 1);
    vector<int> b(m + 1);
    for (int i = 0; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 0; i <= m; i++){
        cin >> b[i];
    }
    vector<int> res = multiply(a, b);

    for (int i = 0; i < cnt - offset; i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}