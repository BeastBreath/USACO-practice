#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int N;

struct cow {
    int arrival, time, seniority;
    bool operator<(const cow& y) {
        if (arrival != y.arrival) return arrival < y.arrival;
        else if (arrival == y.arrival) return seniority < y.seniority;
    }
    bool operator>(const cow& y) {
        if (arrival != y.arrival) return arrival > y.arrival;
        else if (arrival == y.arrival) return seniority > y.seniority;
    }
};

//int max(int a, int b) {if (a>b) return a; else return b;}

int main() {
    freopen("convention2.in", "r", stdin);
    //freopen(".convention2,out", "w", stdout);


    cin >> N;
    vector<cow> cows(N);
    set<int> importantTimes;
    int sen = N;
    
    for (auto& c: cows) {
        c.seniority = sen; sen--;
        cin >> c.arrival >> c.time;
        importantTimes.insert(c.arrival);
    }
    sort(cows.begin(), cows.end(), [](const cow& a, const cow& b) { return a.arrival < b.arrival;});
    for (auto& c: cows) {
        cout << c.seniority << " " << c.arrival << " " << c.time << endl;
        
    }

    vector<cow> queue;
    int waitTime[N];
    int maxWait = 0;
    
    for (int i = 0; i < N; i++) waitTime[i] = 0;

    cow *currentCow = NULL; int time = *importantTimes.begin(); int outTime = time + cows.begin()->time;
    cout << time << endl;
    while (!cows.empty() || !queue.empty()) {
        cout << "TIME: " << time << endl;
        if (currentCow)
            cout << "CurrentCow: " << currentCow->seniority << endl;
        cout << "TIMES: ";
        for (auto a: importantTimes) cout << a << " ";
        cout << endl;
        
        cout << "cows: ";
        for (auto a: cows) cout << a.seniority << " ";
        cout << endl << "queue: ";
        for (auto a: queue) cout << a.seniority << " ";
        cout << endl;

        cout << "Wait times: ";
        for (int i = 0; i < N; i++) {
            cout << waitTime[i] << " ";
        } cout << endl;

        if (currentCow)
            cout << "CurrentCow2: " << currentCow->seniority << endl;
        while (!cows.empty() && cows.begin()->arrival == time) {
            maxWait = max(maxWait, waitTime[cows.begin()->seniority]);
            queue.push_back(*(cows.begin()));
            cows.erase(cows.begin());
            cout << (cows.begin()->arrival) << endl;
        }

        if (currentCow)
            cout << "CurrentCow3: " << currentCow->seniority << endl;
        sort(queue.begin(), queue.end(), [](const cow& a, const cow& b) { return a.seniority > b.seniority;});
        if (time == outTime) {
            cout << "COW LEAVING" << endl;
            currentCow = NULL;
        }

        if (currentCow)
            cout << "CurrentCow4: " << currentCow->seniority << endl;
        if (!currentCow) {
            cout << "NEW COW" << endl;
            currentCow = &queue[0];
            queue.erase(queue.begin());
            outTime = time + currentCow->time;
            importantTimes.insert(outTime);
        }
        importantTimes.erase(importantTimes.begin());
        for (auto a: queue) {
            waitTime[a.seniority] += *importantTimes.begin() - time;
            maxWait = max(maxWait, waitTime[a.seniority]);
        }
        time = *importantTimes.begin(); 
    }
    cout << maxWait;
}