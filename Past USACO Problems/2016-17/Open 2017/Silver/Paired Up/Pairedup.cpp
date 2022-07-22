#include <bits/stdc++.h>

using namespace std;

int max(int a, int b) {if (a > b) return a; else return b;}
int min(int a, int b) {if (a < b) return a; else return b;}


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
    freopen("pairup.in","r",stdin);
    freopen("pairup.out", "w", stdout);
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
        if (herd[first].number == 0) {
            first++;
        }
        if (herd[second].number == 0) {
            second--;
        }
        maxTime = max(maxTime, herd[first].gal + herd[second].gal);
        int m = min(herd[first].number, herd[second].number);
        herd[first].number -= m;
        herd[second].number -= m;
    }
    cout << maxTime;

}