#include <bits/stdc++.h>
#include <stdio.h>
#include <ctype.h>

using namespace std;

map<int, map<int, int>> m;



int main() {
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out","w",stdout);
    int N;
    cin >> N;
    char input1[15], input2[4];
    for (int i = 0; i < N; i++) {
        cin >> input1;
        int in1 = ((int)toupper(input1[0])) + 1000*((int)toupper(input1[1]));
        cin >> input2;
        int in2 = ((int)toupper(input2[0])) + 1000*((int)toupper(input2[1]));
        //cout << input1 << " " << in1 << " " << input2 << " " << in2 << endl;
        if (m.count(in1) == 1) {
            if (m[in1].count(in2) == 1) {
                m[in1][in2]++;
            }
            else {
                m[in1][in2] = 1;
            }
        }
        else {
            m[in1][in2] = 1;
        }
    }
    float total = 0;
    for (const auto & x: m) {
        for (const auto &y: x.second) {
            if (x.first == y.first) {
                //total += m[y.first][x.first] * (m[y.first][x.first] - 1) / 2.0;
            }
            else if (m.count(y.first) == 1 && m[y.first].count(x.first) == 1) {
                //cout << y.first << " " << x.first << " " << endl;
                //cout << m[y.first][x.first] << "  " << m[x.first][y.first] << endl;
                total += (m[y.first][x.first] * m[x.first][y.first]) / 2.0;
            }
        }
    }
    cout << total;
}