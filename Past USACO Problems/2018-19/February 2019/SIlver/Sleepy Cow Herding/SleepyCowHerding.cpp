#include <bits/stdc++.h>

using namespace std;

int N, positions[100000], A[100000];


int solve_min(void)
{
  if (A[N-2]-A[0] == N-2 && A[N-1]-A[N-2]>2) return 2;
  if (A[N-1]-A[1] == N-2 && A[1]-A[0]>2) return 2;
  int first = 0, second = 0, maxDist = N-1, currentDist = 0, maxCows = 1;
    while (first < N && second < N) {
        while (second < N - 1) {
            //cout << "1: " << first  << " " << second << " " << second - first + 1 << " " << currentDist << endl;;
            currentDist += positions[second + 1] - positions[second];
            second++;
            //cout << "2: " << first  << " " << second << " " << second - first + 1 << " " << currentDist << endl;;
            if (currentDist > maxDist) {
                currentDist -= positions[second] - positions[second - 1];
                second--;
                break;
            }
            //cout << "3: " << first  << " " << second << " " << second - first + 1 << " " << currentDist << endl;;
        }
        //cout << "4: " << first  << " " << second << " " << second - first + 1 << " " << currentDist << endl;;
        maxCows = max(maxCows, second - first + 1);
        currentDist -= positions[first + 1] - positions[first];
        first++;
        //cout << "5: " << first  << " " << second << " " << second - first + 1 << " " << currentDist << endl;;

    }
    return N - maxCows;
}

int main() {
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> positions[i];
        A[i] = positions[i];
    }
    sort(positions, positions + N);
    sort(A, A+N);


    /*
    //solve for min
    //int first = 0, second = 1, maxDist = N - 1, currentDist = positions[1] - positions[0], maxCows = 1, currentCows = 1;
    //int first = 0, second = 0, current_distance;
    int first = 0, second = 0, maxDist = N-1, currentDist = 0, maxCows = 1;
    while (first < N && second < N) {
        while (second < N - 1) {
            //cout << "1: " << first  << " " << second << " " << second - first + 1 << " " << currentDist << endl;;
            currentDist += positions[second + 1] - positions[second];
            second++;
            //cout << "2: " << first  << " " << second << " " << second - first + 1 << " " << currentDist << endl;;
            if (currentDist > maxDist) {
                currentDist -= positions[second] - positions[second - 1];
                second--;
                break;
            }
            //cout << "3: " << first  << " " << second << " " << second - first + 1 << " " << currentDist << endl;;
        }
        //cout << "4: " << first  << " " << second << " " << second - first + 1 << " " << currentDist << endl;;
        maxCows = max(maxCows, second - first + 1);
        currentDist -= positions[first + 1] - positions[first];
        first++;
        //cout << "5: " << first  << " " << second << " " << second - first + 1 << " " << currentDist << endl;;

    }
    cout << N - maxCows << endl;*/
    cout << solve_min() << endl;


    //solving for max
    int gaps = positions[N - 1] - positions[0] + 1 - N;
    int minEndGap = max(1,min(positions[N - 1] - positions[N - 2], positions[1] - positions[0]));
    int maxTime = gaps - minEndGap + 1;
    cout << maxTime;
}

/*
    int N;
    cin >> N;

    int positions[N];

    for (int i = 0; i < N; i++) {
        cin >> positions[i];
    }


    sort(positions, positions + N);


    int differences[N - 1];
    for (int i = 0; i < N - 1; i++) {
        differences[i] = positions[i + 1] - positions[i];  
    }

    int minEndGap = min(differences[0], differences[N-2]);
    int maxTime = 1 + positions[N - 1] - positions[0] + 1 - N - minEndGap;

    int max_cows = 0;
    int current_cows = 1;
    int current_length = 0;
    int first = 0, second = 0;
    while (first < N - 1 && second < N-1) {
        while (current_length < N - 1 && second < N-1) {
            current_length += differences[second];
            second++;
            current_cows++;

        }
        if (current_length > N - 1) {
            current_cows--;
            second--;
            current_length -= differences[second];
        }
        max_cows = max(max_cows, current_cows);
        if (second == first) {
            first++; second++;
        }
        else {
            current_cows--;
            current_length -= differences[first];
            first++;
        }
    }
    cout << N - max_cows << endl << maxTime;
}*/

