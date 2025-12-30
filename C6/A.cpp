#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
int n;
double a, b;
typedef struct Point
{
    double x, y;
    Point operator+(const Point &b) const{
        return {x + b.x, y + b.y};
    }
    Point operator-(const Point &b) const{
        return {x - b.x, y - b.y};
    }
    bool operator<(const Point &b) const{
        return x != b.x ? x < b.x : y < b.y;
    }
    Point rotate(double theta) const{
        double c = cos(theta);
        double s = sin(theta);
        return {x * c - y * s, x * s + y * c};
    }

} Point;

Point all[80007];
int cnt = 0;
double cross(Point a, Point b)
{
    return a.x * b.y - a.y * b.x;
}

double cross_product(Point a, Point b, Point c)
{
    return cross(b - a, c - a);
}
double dis(Point a, Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main(){
    int t;
    double xa, ya, xb, yb, xc, yc;
    cin >> t;
    while(t--){
        cin >> xa >> ya >> xb >> yb >> xc >> yc;
        Point a = {xa, ya}, b = {xb, yb}, c = {xc, yc};
        double s = cross_product(b, a, c);
        double di = dis(b, c);
        cout << fixed << setprecision(3) << fabs(s) / di << endl;
    }
    return 0;
}