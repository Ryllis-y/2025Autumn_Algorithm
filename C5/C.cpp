#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
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

Point p[80007];
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


int main(){
    int t;
    cin >> t;
    ll xp1, xp2, yp1, yp2, xq1, xq2, yq1, yq2;
    while (t--){
        cin >> xp1 >> yp1 >> xq1 >> yq1;
        cin >> xp2 >> yp2 >> xq2 >> yq2;
        Point p1 = {xp1, yp1}, p2 = {xp2, yp2}, q1 = {xq1, yq1}, q2 = {xq2, yq2};
        if (cross_product(p1, q1, p2) * cross_product(p1, q1, q2) <= 0 
            && cross_product(p2, q2, p1) * cross_product(p2, q2, q1) <= 0){
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
    }
    return 0;
}