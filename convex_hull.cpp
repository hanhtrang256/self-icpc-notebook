/** convex hull **/
#define X first
#define Y second
using T = long long;
using Point = pair<T, T>;

Point operator - (const Point &a, const Point &b) { return Point(b.X-a.X, b.Y-a.Y); }
Point conj(const Point &p) { return Point(p.X, -p.Y); }
T dot(const Point &a, const Point &b) { return a.X * b.X + a.Y * b.Y; }
T dot(const Point &a, const Point &b, const Point &c) { return dot(b - a, c - a); }
T cross(const Point &a, const Point &b) { return a.X * b.Y - a.Y * b.X; }
T cross(const Point &a, const Point &b, const Point &c) { return cross(b - a, c - a); }

vector < Point > convexHull(vector < Point > p, int n) {
    // sort x ascending, then y
    sort(p.begin(), p.end(), [](const Point &a, const Point &b) {
        if (a.X != b.X) return a.X < b.X;
        return a.Y < b.Y;
    });

    // hull set
    vector < Point > hull;
    hull.push_back(p[0]);

    // upper hull
    for (int i = 1; i < n; ++i) {
        while ((int)hull.size() > 1 && ccw(hull[(int)hull.size() - 2], hull.back(), p[i])) hull.pop_back();
        hull.push_back(p[i]);
    }

    // lower hull
    for (int i = n - 2; i >= 0; --i) {
        while ((int)hull.size() > 1 && ccw(hull[(int)hull.size() - 2], hull.back(), p[i])) hull.pop_back();
        hull.push_back(p[i]);
    }

    if (n > 1) hull.pop_back();
    return hull;
}
/////////////////////////////////////////////////////////////////////////////////////////
/** convex hull trick **/
/** type 1 - complex **/
using T = double;
using P = complex<T>;
T dot(P a, P b) { return (conj(a) * b).real(); }
T cross(P a, P b) { return (conj(a) * b).imag(); }
// k = slope increasing
vector < P > hull, v;
for (int i = 0; i < n; ++i) {
    while (!v.empty() && dot(v.back(), point[i] - hull.back()) < 0) {
        v.pop_back();
        hull.pop_back();
    }
    if (!hull.empty()) v.push_back(1i * (point[i] - hull.back()));
    hull.push_back(point[i]);
}
P query = {x, 1};
auto it = lower_bound(v.begin(), v.end(), query, [](const P &a, const P &b) { return cross(a, b) > 0;} );
return dot(query, hull[it - v.begin()]);
/** type 2 **/
struct CHT {
    struct Line {
        int slope, yIntersect; // a, b
        Line(int _slope = 0, int _yIntersect = 0) { slope = _slope; yIntersect = _yIntersect; }
        long long val(int x) { return 1LL * slope * x + yIntersect; }
        int intersect(Line other) { // (b2 - b1) / (a1 - a2) = x_intersect
            return (other.yIntersect - yIntersect + slope - other.slope - 1) / (slope - other.slope);
        }
    };
    deque<pair<Line, int>> dq; // Line: a, b   int: x -> from x it becomes useful
    void addLine(int slope, int yIntersect) {
        Line nw(slope, yIntersect);
        while ((int)dq.size() >= 2 && dq.back().second >= dq.back().first.intersect(nw))
            dq.pop_back();
        if (dq.empty()) dq.push_back({nw, 0}); // may change to -INF for some problems
        else dq.push_back({nw, dq.back().first.intersect(nw)});
    }
    long long query(int x) { // query x is in order
        while ((int)dq.size() >= 2) {
            if (dq[1].second <= x) dq.pop_front();
            else break;
        }
        return dq[0].first.val(x);
    }
    long long query2(int x) { // query x is not in order -> binary search
        auto qry = *lower_bound(dq.rbegin(), dq.rend(), {Line(0, 0), x},
                                [](const pair<Line,int> &a, const pair<Line, int> &b) {
            return a.second > b.second;
        });
        return qry.first.val(x);
    }
};
