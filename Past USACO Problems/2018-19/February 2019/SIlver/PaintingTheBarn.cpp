#include<iostream>
#include<cstdio>

using namespace std;

int main () {

    freopen("paintbarn.in", "r", stdin);

    freopen("paintbarn.out", "w", stdout);

    int N, K;

    cin >> N >> K;

    int strokes[N][2][2];

    
    int size = 1001;
    int barn[size + 1][size + 1];
    for (int i = 0; i <= size; i++) {
        for (int j = 0; j <= size; j++) {
            barn[i][j] = 0;
        } 
    }


    for (int i = 0; i < N; i++) {
        cin >> strokes[i][0][0] >> strokes[i][0][1] >> strokes[i][1][0] >> strokes[i][1][1];

        for (int j = strokes[i][0][0]; j < strokes[i][1][0]; j++) {
            barn[j][strokes[i][0][1]]++;
            barn[j][strokes[i][1][1]]--;
        }
    }

    int count = 0;
    for (int j = 1; j <= size; j++) {
        for (int i = 1; i <= size; i++) {
            barn[j][i] += barn[j][i - 1];
            if (barn[j][i] == K) {
                count ++;
            }
        }
    } 

    cout << count;

}
