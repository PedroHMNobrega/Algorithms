#include<bits/stdc++.h>
using namespace std;
 
struct Point {
    double x, y;
    Point(double x, double y) : x(x), y(y) {}
};

bool compare(Point a, Point b) {
    return a.x < b.x or (a.x == b.x and a.y < b.y);
}

bool clockwise(Point a, Point b, Point c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0; 
}

bool counterClockwise(Point a, Point b, Point c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0; 
}

void convexHull(vector<Point> &points) {
    if(points.size() == 1) return;
    sort(points.begin(), points.end(), compare); 
    
    Point p1 = points[0], p2 = points.back(); 
    vector<Point> up, down;
    up.push_back(p1);
    down.push_back(p1);

    for(int i = 1; i < points.size(); i++) {
        if(i == points.size() - 1 or clockwise(p1, points[i], p2)) {
            while(up.size() >= 2 and !clockwise(up[up.size()-2], up[up.size()-1], points[i])) 
                up.pop_back();
            up.push_back(points[i]);
        }
        if(i == points.size() - 1 or counterClockwise(p1, points[i], p2)) {
            while(down.size() >= 2 and !counterClockwise(down[down.size()-2], down[down.size()-1], points[i])) 
                down.pop_back();
            down.push_back(points[i]);
        }
    }

    points.clear();
    
    for(int i = up.size() - 2; i > 0; i--)
        points.push_back(up[i]);
    for(int i = 0; i < down.size(); i++) 
        points.push_back(down[i]);

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, x, y;
    while(true) {
        cin >> n;
        if(n == 0) break;
        
        vector<Point> points;
        map<pair<int, int>, bool> aux;
        for(int i = 0; i < n; i++) {
            cin >> x >> y;
            Point point = Point(x, y);
            if(!aux[{x, y}]) { 
                points.push_back(point);
                aux[{x, y}] = true;
            }
        }
        convexHull(points);
        cout << points.size() << '\n';
        for(int i = 0; i < points.size(); i++) cout << points[i].x << " " << points[i].y << "\n";
    }
}