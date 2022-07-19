#include<iostream>
#include<cstdio>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int W_room, H_room, x1, y1, x2, y2, W_table1, H_table1, W_table2, H_table2;
        cin >> W_room >> H_room >> x1 >> y1 >> x2 >> y2 >> W_table2 >> H_table2;
        W_table1 = x2-x1;
        H_table1 = y2-y1;
        int min_distance = -1;
        //if (W_room < W_table1 + W_table2 && )
        if (W_room >= W_table1 + W_table2) {
            min_distance = max(0,min(W_table2 - x1, W_table2 - (W_room - x2)));
        }
        if (H_room >= H_table1 + H_table2) {
            if (min_distance == -1) {
                min_distance = max(0,min(H_table2 - y1, H_table2 - (H_room - y2)));
            }
            else {
                min_distance = min(min_distance, max(0,min(H_table2 - y2, H_table2 - (H_room - y2))));
            }
        }
        cout << min_distance << endl;
    }
}