#include<iostream>
#include<cstdio>

using namespace std;

int main () {
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);

    int N, K, B;
    cin >> N >> K >> B;

    bool brokenSignals[N];
    for (int i = 0; i < N; i++) {
        brokenSignals[i] = 0;
    }
    for (int i = 0; i < B; i++) {
        int b;
        cin >> b;
        brokenSignals[b - 1] = 1;
    }

    int minRepair = 0, current;
    for (int i = 0; i < K; i++) {
        minRepair += brokenSignals[i];
    }
    current = minRepair;
    for (int i = K; i < N; i++) {
        current = current - brokenSignals[i-K] + brokenSignals[i];
        minRepair = min(current, minRepair);
    }

    cout << minRepair;

}

// 0 0 1 1 0 1 1 1 0 0
//            3 2 1