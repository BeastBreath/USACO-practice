#include <bits/stdc++.h>

using namespace std;


typedef pair<int, int> base;

bool findFirst(base a, base b) {
    if (a.first != b.first) return a.first < b.first;
    else return a.second > b.second;
}


int main() {
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
    int N;
    cin >> N;

    base mountains[N];

    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        mountains[i] = {a - b, a + b};
    }
    sort(mountains, mountains + N, findFirst);


    int shown = 1;
    int currentMountain = 0;
    int previousRight = mountains[currentMountain].second;
    while (currentMountain < N) {
        while(previousRight >= mountains[currentMountain].second && currentMountain != N) {
            currentMountain++;
        }
        if (currentMountain < N) {
            shown++;
            previousRight = mountains[currentMountain].second;
        } 
    }
    cout << shown;

}
/*
bool findFirst(pair a, pair b) {
    if (a.first != b.first) return a.first < b.first;
    else return a.second < b.second;
}*/