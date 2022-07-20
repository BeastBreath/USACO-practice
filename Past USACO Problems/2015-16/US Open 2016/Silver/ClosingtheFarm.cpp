#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int N, M;
vector<int> adjacencyList[3000];

int main() {
    freopen("closing.in","r",stdin);
    freopen("closing.out", "w", stdout);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        adjacencyList[a].push_back(b);
        adjacencyList[b].push_back(a);
    }



}

int removeNode(int n) {
    
}