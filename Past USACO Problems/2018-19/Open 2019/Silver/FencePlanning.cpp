#include<iostream>
#include<cstdio>
#include<vector>
#include <bits/stdc++.h>

using namespace std;

int N, K;
int size = 100000;
int x[100000], y[100000];
bool visited[100000];
vector<int> adjacencyList[100000];
int minPerimeter = INT_MAX;
int currentMinX = INT_MAX, currentMinY = INT_MAX, currentMaxX = INT_MIN, currentMaxY = INT_MIN;

void dfs (int n);

int main() {
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);

    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        visited[i] = false;
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        adjacencyList[a].push_back(b);
        adjacencyList[b].push_back(a);
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            dfs(i);
            minPerimeter = min(minPerimeter, 2 * (currentMaxX - currentMinX + currentMaxY - currentMinY));
        }
        currentMinX = INT_MAX, currentMinY = INT_MAX, currentMaxX = INT_MIN, currentMaxY = INT_MIN;
    }
    cout << minPerimeter;


}

void dfs (int n) {
    if (visited[n]) return;
    visited[n] = true;
    currentMinX = min(currentMinX, x[n]);
    currentMaxX = max(currentMaxX, x[n]);
    currentMinY = min(currentMinY, y[n]);
    currentMaxY = max(currentMaxY, y[n]);
    for (auto u: adjacencyList[n]) {
        dfs(u);
    }
}