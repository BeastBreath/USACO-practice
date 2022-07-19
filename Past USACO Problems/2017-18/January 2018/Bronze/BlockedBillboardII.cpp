#include<iostream>
#include<cstdio>

using namespace std;

int main() {
    
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    int x1a, y1a, x2a, y2a, x1b, y1b, x2b, y2b;
    cin >> x1a >> y1a >> x2a >> y2a >> x1b >> y1b >> x2b >> y2b;
    int area = 1;
    if (x1a >= x1b && x2a <= x2b) {
        if ((y1b > y1a && y2b < y2a)) {
            area = y2a - y1a;
        }
        else if (y1b <= y1a && y2b >= y2a) {
            area = 0;
        }
        else if (y1a <= y2b && y2b <= y2a) {
            area = max(0,y2a - y2b);
        }
        else if (y1a <= y1b && y1b <= y2a) {
            area = max(0,y1b - y1a);
        }
    }
    else {
        area = y2a - y1a;
    }
    if (y1a >= y1b && y2a <= y2b) {
        if ((x1b > x1a && x2b < x2a)) {
            area *= x2a - x1a;
        }
        else if (x1b <= x1a && x2b >= x2a) {
            area *= 0;
        }
        else if (x1a <= x2b && x2b <= x2a) {
            area *= max(0,x2a - x2b);
        }
        else if (x1a <= x1b && x1b <= x2a) {
            area *= max(0,x1b - x1a);
        }
    }
    else {
        area *= (x2a - x1a);
    }
    cout << area << endl;
}

//595441