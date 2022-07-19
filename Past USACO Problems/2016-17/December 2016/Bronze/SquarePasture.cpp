#include<iostream>
#include<cstdio>

using namespace std;

int main () {

    freopen("square.in", "r", stdin);

    freopen("square.out", "w", stdout);

    int minx = 11, miny = 11, maxx = -1, maxy= -1;
    for (int i = 0; i < 4; i++) {
        int a, b;
        cin >> a >> b;
        minx = min(a, minx);
        miny = min(b, miny);
        maxx = max(a, maxx);
        maxy = max(b, maxy);
    }

    cout << max((maxy-miny),(maxx-minx)) * max((maxy-miny),(maxx-minx));
    
}
