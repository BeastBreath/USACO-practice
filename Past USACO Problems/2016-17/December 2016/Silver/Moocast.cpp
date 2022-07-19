#include<iostream>
#include<cstdio>
#include<math.h>
#include<vector>

using namespace std;

struct cow {
    int x, y, p;
    cow() {
        
    }
    cow (int nx, int ny, int np) {
        x = nx;
        y = ny;
        p = np;
    }
};

bool visited[200];
vector<int> adjacencyList[200];
cow* cows[200];
int N;
int max_connected = 0;
int currently_connected = 0;

int dist(int x1, int y1, int x2, int y2);
void createAdjacency ();
void dfs (int n);

int main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);


    cin >> N;


    for (int i = 0; i < N; i++) {
        visited[i] = false;
        int x, y, p; cin >> x >> y >> p;
        cows[i] = new cow(x, y, p);
    }
    createAdjacency();
    for (int i = 0; i < N; i++) {
        for (int i = 0; i < N; i++) {
            visited[i] = false;
        }
        dfs(i);
        max_connected = max(max_connected, currently_connected);
        currently_connected = 0;
    }
    cout << max_connected;

}


void dfs (int n) {
    if (visited[n]) return;
    currently_connected++;
    visited[n] = true;
    for (auto u: adjacencyList[n]) {
        dfs(u);
    }
}


void createAdjacency () {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (dist(cows[i]->x, cows[i]->y, cows[j]->x, cows[j]->y) <= (cows[i]->p * cows[i]->p)) {
                adjacencyList[i].push_back(j);
            }
        }
    }
}

int dist(int x1, int y1, int x2, int y2) {
    return (x2-x1) * (x2-x1) + (y2-y1) * (y2-y1);
}