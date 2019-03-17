#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define pb push_back
#define forn(a,b) for(int a=0; a<b; a++)

struct Point {
    ll x, y;
    Point(ll a, ll b) {
        x = a;
        y = b;
    }
    bool operator<(const Point &other) const{
        if(x == other.x) {
            return y < other.y;
        }
        return x < other.x;
    }
};

ll cross(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    vector<Point> upper_hull;
    vector<Point> lower_hull;
    vector<Point> pts;
    for(int i = 0; i < N; i++) {
        ll x, y; cin >> x >> y;
        pts.pb(Point(x, y));
    }
    // upper hull
    for(int i = 0; i < pts.size(); i++) {
        while(upper_hull.size() >= 2 && cross(upper_hull[upper_hull.size()-2], upper_hull[upper_hull.size()-1], pts[i]) >= 0) {
            upper_hull.pop_back();
        }
        upper_hull.push_back(pts[i]);
    }

    //lower hull
    for(int i = pts.size()-1; i >= 0; i--) {
        while(lower_hull.size() >= 2 && cross(lower_hull[lower_hull.size()-2], lower_hull[lower_hull.size()-1], pts[i]) <= 0) {
            lower_hull.pop_back();
        }
        lower_hull.push_back(pts[i]);
    }
    vector<Point> hull;
    for(int i = 0; i < lower_hull.size(); i++) {
        hull.pb(lower_hull[i]);
    }
    for(int i = 0; i < upper_hull.size(); i++) {
        hull.pb(upper_hull[i]);
    }

    return 0;
}
