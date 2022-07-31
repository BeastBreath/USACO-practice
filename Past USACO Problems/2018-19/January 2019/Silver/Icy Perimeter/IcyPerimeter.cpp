#include "iostream"
#include "cstdio"

using namespace std;

bool grid[1005][1005];
bool visited[1005][1005];
int N, gridSize;
int maxArea = -1, perimeter = -1, currentArea = 0, currentPerimeter = 0;

void flood_fill(int r, int c) {
    if (visited[r][c] || !grid[r][c]) return;
    visited[r][c] = true;
    if (!grid[r][c+1]) currentPerimeter++;
    if (!grid[r][c-1]) currentPerimeter++;
    if (!grid[r+1][c]) currentPerimeter++;
    if (!grid[r-1][c]) currentPerimeter++;
    currentArea++;
    flood_fill(r+1, c);
    flood_fill(r-1, c);
    flood_fill(r, c+1);
    flood_fill(r, c-1);
}

int main() {
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    
    cin >> N;
    gridSize = N + 2;
    for (int i = 0; i < gridSize; i++) {
        grid[0][i] = false;
        grid[0][gridSize - 1] = false;
        grid[i][0] = false;
        grid[i][gridSize - 1] = false;
        visited[0][i] = false;
        visited[0][gridSize - 1] = false;
        visited[i][0] = false;
        visited[i][gridSize - 1] = false;
    }
    for (int i = 1; i < gridSize - 1; i++) {
        for (int j = 1; j < gridSize - 1; j++) {
            char gridSpot;
            cin >> gridSpot;
            grid[i][j] = gridSpot == '#';
            visited[i][j] = false;
        }
    }
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            if(!visited[i][j]) {
                currentArea = 0; currentPerimeter = 0;
                flood_fill(i,j);
                if (currentArea > maxArea) {
                    maxArea = currentArea;
                    perimeter = currentPerimeter;
                }
                else if (currentArea == maxArea) {
                    perimeter = min(perimeter, currentPerimeter);
                }
            }
        }
    }
    cout << maxArea << " " << perimeter;
}