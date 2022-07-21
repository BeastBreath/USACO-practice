#include<iostream>
#include <cstdio>

using namespace std;

int N, K;
int grid[1200][1200];
int gridSize;
int maxGrass = 0;

int calculateVol (int r, int c);

int main() {
    freopen("lazy.in","r",stdin);
    freopen("lazy.out", "w", stdout);


    cin >> N >> K;
    gridSize = N + 2*K;
    
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < gridSize; j++) {
            grid[i][j] = 0;
            grid[j][i] = 0;
            grid[j][gridSize - 1 - i] = 0;
            grid[gridSize - 1 - i][j] = 0;
        }
    }

    for (int i = K; i < gridSize - K; i++) {
        for (int j = K; j < gridSize - K; j++) {
            cin >> grid[i][j];
        }
    }
    int currentSum = 0;
    
    int r = K, c = K;
    maxGrass = calculateVol(r,c);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            maxGrass = max(maxGrass, calculateVol(r+i, c+j));
        }
    }
    cout << maxGrass;


}

int calculateVol (int r, int c) {
    int currentSum = 0;
    int counter = 0;
    bool switcht = true;
    for (int i = r - K; i <= r + K; i++) {
        for (int j = r - counter; j <= r + counter; j++) {
            currentSum += grid[i][j];
        }
        if (counter == K) {
            switcht = false;
        }
        if (switcht) {
            counter++;
        }
        else {
            counter--;
        }

    }
    
    /*
    for (int i = r - K; i <= r + K; i++) {
        if (i <= r) {
            for (int j = c - i; j <= c + i; j++) {
                currentSum += grid[i][j];
            }
        }
        else if (i > r) {
            int techI = r + K - i;
            for (int j = c - techI; j <= c + techI; j++) {
                currentSum += grid[i][j];
            }
        }
    }*/
    return currentSum;
}