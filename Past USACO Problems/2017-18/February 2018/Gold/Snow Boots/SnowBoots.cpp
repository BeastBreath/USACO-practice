#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <queue>

using namespace std;

struct boot {
    int d, s;
    bool operator<(const boot& y) {
        if (d != y.d) return d < y.d;
        else return s < y.s;
    }
    bool operator>(const boot& y) {
        if (d != y.d) return d > y.d;
        else return s > y.s;
    }
};


int N, B;
int tiles[100005];
boot boots[100005];
priority_queue<int> toCheck;

bool checkBoot(int b) {
    toCheck.push(0);
    while(!toCheck.empty()) {
        int t = toCheck.top();
        if (t >= N) {
            return true;
        }
        toCheck.pop();
        for (int i =  t + boots[b].s; i > t; i--) {
            if (i >= N) return true;
            if (tiles[i] <= boots[b].d) {
                toCheck.push(i);
                break;
            } 
        }
    }
    return false;
}

int main() {
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);

    cin >> N >> B;N++;
    tiles[0] = 0;
    for (int i = 1; i < N; i++) {
        cin >> tiles[i];
    }
    int lastoutput = 0;
    for (int i = 0; i < B; i++) {
        cin >> boots[i].d >> boots[i].s;
        /*if (i > 0 && lastoutput == 1 && (boots[i].s >= boots[i - 1].s && boots[i].s >= boots[i - 1].s)) {
            cout << 1 << endl;        
        }*/
        //else {
            if(checkBoot(i)) {cout << 1 << endl; lastoutput = 1;}
            else {cout << 0 << endl; lastoutput = 0;}
        //}
    }

}