#include <bits/stdc++.h>

using namespace std;

map<int, int> maxPerRow;
map<int, int> minPerRow;
map<int, int> maxPerColumn;
map<int, int> minPerColumn;

int main() {
    freopen("split.in" , "r", stdin);
    //freopen("split.out", "w", stdout);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        if (maxPerRow.count(x) == 1) {
            maxPerRow[x] = max(y, maxPerRow[x]);
            minPerRow[x] = min(y, minPerRow[x]);
        }
        else {
            maxPerRow[x] = y;
            minPerRow[x] = y;
        }
        if (maxPerColumn.count(y) == 1) {
            maxPerColumn[y] = max(x, maxPerColumn[y]);
            minPerColumn[y] = min(x, minPerColumn[y]);
        }
        else {
            maxPerColumn[y] = x;
            minPerColumn[y] = x;
        }
    }
    
    for (const auto& x : maxPerColumn) {
	    cout << x.first << " " << x.second << endl;
    }cout << endl;
    for (const auto& x : minPerColumn) {
	    cout << x.first << " " << x.second << endl;
    }cout << endl;
    for (const auto& x : maxPerRow) {
	    cout << x.first << " " << x.second << endl;
    }cout << endl;
    for (const auto& x : minPerRow) {
	    cout << x.first << " " << x.second << endl;
    }cout << endl;
}