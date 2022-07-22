#include <bits/stdc++.h>

using namespace std;


struct store {
    int price;
    int gallons;
    store () {}
    bool operator<(const store& y) { return price < y.price; }

};

int N, M, R;
int cowMilk[1000005];
store *stores[1000005];
int rentalPrice[1000005];
int currentStore, currentRent, currentCow;

int min(int a, int b);
int changePrice();
int calculatePrice();
int compStore(store *a, store *b) {return a->price > b->price;}


int main() {
    freopen("rental.in","r",stdin);
    //freopen("rental.out", "w", stdout);
    cin >> N >> M >> R;
    for (int i = 0; i < N; i++) {
        cin >> cowMilk[i];
    }
    for (int i = 0; i < M; i++) {
        stores[i] = new store();
        cin >> stores[i]->gallons;
        cin >> stores[i]->price;
    }
    for (int i = 0; i < R; i++) {
        cin >> rentalPrice[i];
    }
    
    sort(cowMilk, cowMilk + N, greater<int>());
    sort(rentalPrice, rentalPrice + R, greater<int>());
    sort(stores, stores + M, compStore);

    long long maxPrice = 0;

    currentStore = 0;
    currentRent = 0;
    currentCow = 0;
    while (currentCow < N) {
        if (currentStore == M && currentRent == R) {
            break;
        }
        else if (currentStore == M) {
            maxPrice += rentalPrice[currentRent];
            currentRent++;
            N--;
        }
        else if (currentRent == R) {
            maxPrice += changePrice();
            currentCow++;
        }
        else if (calculatePrice() > rentalPrice[currentRent]) {
            maxPrice += changePrice();
            currentCow++;

        }
        else {
            maxPrice += rentalPrice[currentRent];
            currentRent++;
            N--;
        }
    }
    cout << maxPrice;
    
}

int calculatePrice() {
    int retPrice = 0;
    int galLeft = cowMilk[currentCow];
    int tempCurrentStore = currentStore;
    while (galLeft > 0 && tempCurrentStore != M && currentRent != R) {
        retPrice += stores[tempCurrentStore]->price * min(stores[tempCurrentStore]->gallons, galLeft);
        galLeft -= min(stores[tempCurrentStore]->gallons, galLeft);
        tempCurrentStore++;
    }
    return retPrice;
}


int changePrice() {
    int retPrice = 0;
    while (cowMilk[currentCow] > 0 && currentStore != M && currentRent != R) {
        retPrice += stores[currentStore]-> price * min(stores[currentStore]->gallons, cowMilk[currentCow]);
        int m = min(stores[currentStore]->gallons, cowMilk[currentCow]);
        cowMilk[currentCow] -= m;
        stores[currentStore]->gallons -= m;
        if (cowMilk[currentCow] > 0) {
            currentStore++;
        }
    }
    return retPrice;
}

int min(int a, int b) {
    if (a<b) return a;
    else return b;
}