#include <iostream>
#include <cstdio>
#include <set>
#include <queue>
#include <set>

using namespace std;


int N, M;
set<pair<int, int>> lightSwitches[105][105];
bool visited[105][105];
bool lightsOn[105][105];
int on = 0;

bool checkSpot(int r, int c) {
    //cout << "RC " << r << " " << c << endl;
    for (int i = -1; i <= 1; i += 1) {
        for (int j = -1; j <= 1; j += 1) {
            //cout << r + i  << " " << j + c << "\t";
            //cout << (r + i < 0 && r + i >= N && c + j < 0 && c + j >= N) << " " << lightsOn[r + i][c + j] << " " << visited[r + i][c + j] << endl;
            if (!(r + i < 0 && r + i >= N && c + j < 0 && c + j >= N)  // if out of bounds
                && lightsOn[r + i][c + j]  // wrong color
                && visited[r + i][c + j]
            ){  return true; }
        }
    }
    //cout << "RETURNING FALSE" << endl;
    return false;
}

void floodFillAdjacent(int r, int c) {
    //cout << "FFA1: " << r << " " << c << endl;
    if (
		(r < 0 || r >= N || c < 0 || c >= N)  // if out of bounds
		|| !lightsOn[r][c]  // wrong color
		|| visited[r][c]
	)return;
    //cout << "FFA2: " << r << " " << c << endl;


    visited[r][c] = true;

    for (auto a: lightSwitches[r][c]) {
        //cout << "LS1 " << a.first << " " << a.second << endl;
        if (!lightsOn[a.first][a.second]) {
            //cout << "LS2 " << a.first << " " << a.second << endl;
            on++;
            lightsOn[a.first][a.second] = true;
            if (checkSpot(a.first, a.second)) {
                //cout << "LS3 " << a.first << " " << a.second << endl;
                floodFillAdjacent(a.first, a.second);
            }
        }
    }
    
    floodFillAdjacent(r-1, c);
    floodFillAdjacent(r+1, c);
    floodFillAdjacent(r, c-1);
    floodFillAdjacent(r, c+1);
}

int main() {
    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);
    

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
            lightsOn[i][j] = false;
        }
    }

    for (int i = 0; i < M; i++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b; x--; y--; a--; b--;
        lightSwitches[x][y].insert({a, b});
    }

    on = 1;
    lightsOn[0][0] = true;

    floodFillAdjacent(0,0);

    cout << on;  
    
}

/*

int N, M;
set<pair<int, int>> lightSwitches[105][105];
bool canVisit[105][105];
bool visited[105][105];
bool lightsOn[105][105];
int on = 0;
*/