#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N;
int max_cows = 100005;
vector<int> shiftChanges;
pair<int, int> shifts[1000050];
int differenceArray[1000050]; 
int width[1000050];
int intervalValue[1000005];
int prefixSums[1000050];
int ones[1000050];
int covered;

int getCompressedIndex(int a) {
	return lower_bound(shiftChanges.begin(), shiftChanges.end(), a) - shiftChanges.begin();
}


int min(int a, int b) {
    if (a<b) return a;
    else return b;
}




int main() {
    freopen("lifeguards.in","r",stdin);
    freopen("lifeguards.out", "w", stdout);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b; a++; b++;
        shifts[i] = {a, b};
        shiftChanges.push_back(a);
        shiftChanges.push_back(b);
        differenceArray[i] = 0;
    }


    sort(shiftChanges.begin(), shiftChanges.end());

    shiftChanges.erase(unique(shiftChanges.begin(), shiftChanges.end()), shiftChanges.end());

    int newN = shiftChanges.size();

    for (int i = 0; i < N; i++) {
        differenceArray[getCompressedIndex(shifts[i].first)]++;
        differenceArray[getCompressedIndex(shifts[i].second)]--;
    }

    for (int i = 0; i < newN; i++) {
        ones[i] = 0;
    }

    covered = 0;

    //Width is between this one and the previous one

    for (int i = 1; i < newN; i++) {
        width[i] = shiftChanges[i] - shiftChanges[i - 1];
    }

    prefixSums[0] = differenceArray[0];
    ones[0] = 0;
    for (int i = 1; i < newN; i++) {
        prefixSums[i] = prefixSums[i - 1] + differenceArray[i];
        if (prefixSums[i - 1] == 1) {
            ones[i] = width[i] + ones[i - 1];
        }
        else {
            ones[i] = ones[i - 1];
        }
        if (prefixSums[i - 1] >= 1) {
            covered += width[i];
        }
    }
    long long minlost = shiftChanges[shiftChanges.size() - 1] - shiftChanges[0];
    for (int i = 0; i < N; i++) {
        minlost = min(minlost, ones[getCompressedIndex(shifts[i].second)] - ones[getCompressedIndex(shifts[i].first)]);
    }
    cout << covered - minlost << endl;
    

}

/*
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
0 1 1 2 1 2 2 2 1 0 0  0  0  0  0


*/