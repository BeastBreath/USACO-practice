#include<iostream>
#include<cstdio>

using namespace std;

int main () {

    freopen("paintbarn.in", "r", stdin);
    cout << "START" << endl;

    //freopen("paintbarn.out", "w", stdout);
    cout << "START2" << endl;

    int N, K;

    cin >> N >> K;

    cout << "START3" << endl;

    int strokes[N][2][2];

    
    int size = 1001;
    int barn[size + 1][size + 1];
    for (int i = 0; i <= size; i++) {
        for (int j = 0; j <= size; j++) {
            barn[i][j] = 0;
        } 
    }

    cout << "Done with setup" << endl;

    for (int i = 0; i < N; i++) {
        cin >> strokes[i][0][0] >> strokes[i][0][1] >> strokes[i][1][0] >> strokes[i][1][1];
        
        barn[strokes[i][0][0]][strokes[i][0][1]]++; //x1y1
        barn[strokes[i][0][0]][strokes[i][1][1]]--; //x1y2
        barn[strokes[i][1][0]][strokes[i][0][1]]--; //x2y1
        barn[strokes[i][1][0]][strokes[i][1][1]]++; //x2y2
    }

    cout << "Done with Input" << endl;
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            barn[i][j] = barn[i][j] + barn[i][j-1];
        }
    }
    
    cout << "Done with first layer" << endl;

    int count = 0;
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            barn[j][i] = barn[j][i] + barn[j-1][i];
            if (barn[j][i] == K) {
                count ++;
            } 
        }
    }


    cout << "C: " << count;

}
