#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const double PI = acos(-1.0);
int n;
double a, b;
typedef struct Point
{
    ll x, y;
    Point operator+(const Point &b) const
    {
        return {x + b.x, y + b.y};
    }
    Point operator-(const Point &b) const
    {
        return {x - b.x, y - b.y};
    }
    bool operator<(const Point &b) const
    {
        return x != b.x ? x < b.x : y < b.y;
    }
    // Point rotate(double theta) const
    // {
    //     double c = cos(theta);
    //     double s = sin(theta);
    //     return {x * c - y * s, x * s + y * c};
    // }

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
double getS(Point a, Point b, Point c){
    double s = cross_product(b, a, c) / 2;
    return fabs(s);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> all[i].x >> all[i].y;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++){
        int j = (i + 1) % n;
        ans += cross(all[i], all[j]);
    }
    cout << llabs(ans) << endl;
    return 0;
}