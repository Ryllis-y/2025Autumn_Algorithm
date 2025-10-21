#include <bits/stdc++.h>

using namespace std;

struct Point {
    double x, y;
};

bool compareX(const Point& a, const Point& b) {
    return a.x < b.x;
}

bool compareY(const Point& a, const Point& b) {
    return a.y < b.y;
}

double distance(const Point& a, const Point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}


double bruteForce(const vector<Point>& points, int left, int right) {
    double minDist = numeric_limits<double>::max();
    for (int i = left; i <= right; i++) {
        for (int j = i + 1; j <= right; j++) {
            minDist = min(minDist, distance(points[i], points[j]));
        }
    }
    return minDist;
}

double stripClosest(vector<Point>& strip, double d) { //检查跨左右区域
    double minDist = d;
    int size = strip.size();
    
    sort(strip.begin(), strip.end(), compareY);
    
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < minDist; j++) { //通过y坐标差剪枝
            minDist = min(minDist, distance(strip[i], strip[j]));
        }
    }
    return minDist;
}

double closestUtil(vector<Point>& points, int left, int right) {
    
    if (right - left + 1 <= 3) {    //小规模直接算
        return bruteForce(points, left, right);
    }
    
    int mid = left + (right - left) / 2;
    Point midPoint = points[mid];
    //分治左右
    double dLeft = closestUtil(points, left, mid);
    double dRight = closestUtil(points, mid + 1, right);
    double d = min(dLeft, dRight);
    
    vector<Point> strip;
    for (int i = left; i <= right; i++) {
        if (abs(points[i].x - midPoint.x) < d) {
            strip.push_back(points[i]); //收集带状区域点
        }
    }
    
    return min(d, stripClosest(strip, d));
}

double closestPair(vector<Point>& points) {
    sort(points.begin(), points.end(), compareX);
    return closestUtil(points, 0, points.size() - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    
    double result = closestPair(points);
    cout << fixed << setprecision(4) << result << endl;
    
    return 0;
}