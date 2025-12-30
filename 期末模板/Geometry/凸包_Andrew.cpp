#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
int n;
double a, b;
typedef struct Point
{
    double x, y;
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
    Point rotate(double theta) const
    {
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
vector<Point> andrew(int sz)
{
    sort(all, all + sz, [](const Point &a, const Point &b)
         { return a < b; });
    vector<Point> hull;
    for (int i = 0; i < sz; i++)
    {
        while (hull.size() >= 2 && cross_product(hull[hull.size() - 2], hull.back(), all[i]) <= 0)
        {
            hull.pop_back();
        }
        hull.push_back(all[i]);
    }
    int len = hull.size();
    for (int i = sz - 2; i >= 0; i--)
    {
        while (hull.size() > len && cross_product(hull[hull.size() - 2], hull.back(), all[i]) <= 0)
        {
            hull.pop_back();
        }
        hull.push_back(all[i]);
    }
    return hull;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cnt = 0;
        double x, y, theta;
        for (int i = 0; i < n; i++){
            cin >> x >> y;
            Point center = {x, y};
            all[cnt++] = center;
        }

        vector<Point> ans = andrew(n);
        double pt = 0;
        for (int i = 0; i < ans.size() - 1; i++){
            pt += dis(ans[i], ans[i + 1]);
        }
        cout << fixed << setprecision(10) << pt << endl;
    }
    return 0;
}