#include<iostream>
#include<cstdio> 

using namespace std;

int main() {
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    int N, Q;

    cin >> N >> Q;

    int cowsByType[3][N + 1];
    cowsByType[0][0] = 0;
    cowsByType[1][0] = 0;
    cowsByType[2][0] = 0;
    for (int i = 1; i <= N; i++) {
        int n;
        cin >> n;
        cowsByType[0][i] = cowsByType[0][i - 1];
        cowsByType[1][i] = cowsByType[1][i - 1];
        cowsByType[2][i] = cowsByType[2][i - 1];
        cowsByType[n - 1][i]++;
    }

    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        
        cout << (cowsByType[0][b] - cowsByType[0][a - 1]) << " ";
        cout << (cowsByType[1][b] - cowsByType[1][a - 1]) << " ";
        cout << (cowsByType[2][b] - cowsByType[2][a - 1]) << endl;

    }


}