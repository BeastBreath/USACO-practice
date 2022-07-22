#include <bits/stdc++.h>

using namespace std;

struct cows {
    int number, gal;
    cows() {}
    cows(int newN, int newG) {
        number = newN;
        gal = newG;
    }
    bool operator<(const cows& y) { return gal < y.gal; }
};

int main() {
    int N;
    cin >> N;
    cows herd[N];
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> herd[i].number >> herd[i].gal;
    }
    sort(herd, herd+N);
    int first = 0, second = N - 1, maxTime = 0;
    while (first < second) {
        maxTime = max()
    }

}