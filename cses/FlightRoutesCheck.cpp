#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int n, m;
int visited[100000];
int numVisited = 0;
vector<int> adjacencyList[100000];



int main() {

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        adjacencyList[a].push_back(b);
    }
    if (numVisited == n) {
        cout << "YES" << endl;
    }
    else {
        cout << "No" << endl;
        int no = -1, yes = -1;
        for (int i = 0; i < n; i++) {
            if (visited[i] && yes != -1) {
                yes = i;
            }
            else if (!visited[i] && no != -1) {
                no = i;
            }
            else if (no != -1 && yes != -1) {
                break;
            }
        }
        yes++; no++;
        cout << yes << " " << no << endl;
    }
}


void dfs(int n) {
    if (visited[n]) return;
    numVisited++;
    for (auto u: adjacencyList[n]) {
        dfs(u);
        if (numVisited == n) {
            return;
        }
    }
}