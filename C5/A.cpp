#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
typedef long long ll;
int n;
typedef struct Point{
    ll x, y;
    Point operator+(const Point& b) const{
        return {x + b.x, y + b.y};
    }
    Point operator-(const Point& b) const{
        return {x - b.x, y - b.y};
    }
    bool operator<(const Point& b) const{
        return x != b.x ? x < b.x : y < b.y;
    }
    // Point rotate(double theta) const {
    //     double c = cos(theta);
    //     double s = sin(theta);
    //     return {x * c - y * s, x * s + y * c};
    // }

}Point;
double cross(Point a, Point b){
    return a.x * b.y - a.y * b.x;
}

double cross_product(Point a, Point b, Point c){
    return cross(b - a, c - a);
}
double dis(Point a, Point b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
Point p[100007];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> p[i].x >> p[i].y;
        }
        Point v = {p[0].x - p[1].x, p[0].y - p[1].y};
        bool flag = true;
        for (int i = 2; i < n; i++){
            Point l = {p[i].x - p[0].x, p[i].y - p[0].y};
            if (cross(v, l) != 0) {
                cout << "how?" << endl;
                flag = false;
                break;
            }
        }
        if (flag == true) cout << "boo how! boo how!" << endl;
    }
    return 0;
}