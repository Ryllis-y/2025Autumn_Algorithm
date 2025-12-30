#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
int n;
double a, b, r;
typedef struct Point{
    double x, y;
    Point operator+(const Point& b) const{
        return {x + b.x, y + b.y};
    }
    Point operator-(const Point& b) const{
        return {x - b.x, y - b.y};
    }
    bool operator<(const Point& b) const{
        return x != b.x ? x < b.x : y < b.y;
    }
    Point rotate(double theta) const {
        double c = cos(theta);
        double s = sin(theta);
        return {x * c - y * s, x * s + y * c};
    }

}Point;

Point f[20007], t[20007], all[80007];
int cnt = 0;
double cross(Point a, Point b){
    return a.x * b.y - a.y * b.x;
}

double cross_product(Point a, Point b, Point c){
    return cross(b - a, c - a);
}
double dis(Point a, Point b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
vector<Point> andrew(int sz){
    sort(all, all + sz, [](const Point& a, const Point& b){
        return a < b;
    });
    vector<Point> hull;
    for (int i = 0; i < sz; i++){
        while (hull.size() >= 2 && cross_product(hull[hull.size() - 2], hull.back(), all[i]) <= 0){
            hull.pop_back();
        }
        hull.push_back(all[i]);
    }
    int len = hull.size();
    for (int i = sz - 2; i >= 0; i--){
        while (hull.size() > len && cross_product(hull[hull.size() - 2], hull.back(), all[i]) <= 0){
            hull.pop_back();
        }
        hull.push_back(all[i]);
    }
    return hull;
}

int main(){
    cin >> n;
    cin >> a >> b >> r;
    double dx = b / 2.0 - r;
    double dy = a / 2.0 - r;
    vector<Point> offsets = {
        {dx, dy},   
        {-dx, dy},  
        {-dx, -dy}, 
        {dx, -dy}   
    };

    double x, y, theta;
    for (int i = 0; i < n; i++){
        cin >> x >> y >> theta;
        Point center = {x, y};
        for (const auto& offset : offsets){
            all[cnt++] = center + offset.rotate(theta);
    }
    }

    vector<Point> ans = andrew(4 * n);
    double pt = 0;
    for (int i = 0; i < ans.size() - 1; i++){
        pt += dis(ans[i], ans[i + 1]);
    }
    pt += 2 * PI * r;
    cout << fixed << setprecision(2) << pt << endl;
    return 0;
}