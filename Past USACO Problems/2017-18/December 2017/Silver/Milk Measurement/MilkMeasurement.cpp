#include <bits/stdc++.h>

using namespace std;

int N, G;
int totalCows;

multiset<int> production;
map<int, int> productionByCow; // Cow, val
map<int, int> cowsByProduction; //val, cows
map<int, pair<int, int>> logs; //day, cow, change

int main() {
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out","w",stdout);
    cin >> N >> G;
    for (int i = 0; i < N; i++) {
        int day, cow, change;
        cin >> day >> cow >> change;
        if (productionByCow.count(cow) == 0) {
            productionByCow[cow] = G;
            production.insert(G);
        }
        logs[day] = {cow, change};
    }
    int maxSoFar = G;
    int numberOfCows = production.size();
    int cowsAtMax = numberOfCows;
    cowsByProduction[G] = numberOfCows;

    int changesToPicture = 0;

    for (auto x: logs) {
        int day = x.first, cow = x.second.first, change = x.second.second;
        if (cowsByProduction.count(productionByCow[cow] + change) == 0) {
            cowsByProduction[productionByCow[cow] + change] = 0;
        }
        if (cowsAtMax == 1 && change > 0 && maxSoFar == productionByCow[cow]) {
            //No change to picture
            //Was at max still is at max
            production.erase(production.find(productionByCow[cow]));
            cowsByProduction[productionByCow[cow]]--;
            productionByCow[cow] += change;
            production.insert(productionByCow[cow]);
            maxSoFar = productionByCow[cow];
            cowsByProduction[productionByCow[cow]]++;
        }
        else if (cowsAtMax == 1 && change < 0 && maxSoFar == productionByCow[cow]) {
            //Check if still the max
            //Was at max, decreased
            if (*(production.lower_bound(productionByCow[cow] + change)) == productionByCow[cow]) {
                //Still the biggest
                production.erase(production.find(productionByCow[cow]));
                cowsByProduction[productionByCow[cow]]--;
                productionByCow[cow] += change;
                production.insert(productionByCow[cow]);
                maxSoFar = productionByCow[cow];
                cowsByProduction[productionByCow[cow]]++;
            }
            else if (*(production.lower_bound(productionByCow[cow] + change)) == productionByCow[cow] + change) {
                //Equal to max
                production.erase(production.find(productionByCow[cow]));
                cowsByProduction[productionByCow[cow]]--;
                productionByCow[cow] += change;
                production.insert(productionByCow[cow]);
                maxSoFar = productionByCow[cow];
                cowsByProduction[productionByCow[cow]]++;
                cowsAtMax = cowsByProduction[productionByCow[cow]];
                changesToPicture++;
            }
            else {
                production.erase(production.find(productionByCow[cow]));
                cowsByProduction[productionByCow[cow]]--;
                productionByCow[cow] += change;
                production.insert(productionByCow[cow]);
                maxSoFar = *(production.lower_bound(productionByCow[cow]));
                cowsByProduction[productionByCow[cow]]++;
                cowsAtMax = cowsByProduction[maxSoFar];
                changesToPicture++;
            }
        }
        else if (cowsAtMax > 1 && change > 0 && maxSoFar == productionByCow[cow]) {
            //More cows at max, not this is the only cow at max
            //Increase Change
            production.erase(production.find(productionByCow[cow]));
            cowsByProduction[productionByCow[cow]]--;
            productionByCow[cow] += change;
            production.insert(productionByCow[cow]);
            maxSoFar = productionByCow[cow];
            cowsByProduction[productionByCow[cow]]++;
            cowsAtMax = 1;
            changesToPicture++;
        }
        else if (cowsAtMax > 1 && change < 0 && maxSoFar == productionByCow[cow]) {
            //More than one cow at max
            //Change in picture
            production.erase(production.find(productionByCow[cow]));
            cowsByProduction[productionByCow[cow]]--;
            productionByCow[cow] += change;
            production.insert(productionByCow[cow]);
            cowsByProduction[productionByCow[cow]]++;
            cowsAtMax--;
            changesToPicture++;
        }
        else if (change < 0 && productionByCow[cow] < maxSoFar) {
            production.erase(production.find(productionByCow[cow]));
            cowsByProduction[productionByCow[cow]]--;
            productionByCow[cow] += change;
            production.insert(productionByCow[cow]);
            cowsByProduction[productionByCow[cow]]++;

        }
        else if (change > 0 && productionByCow[cow] < maxSoFar) {
            if (productionByCow[cow] + change > maxSoFar) {
                //New max alone
                production.erase(production.find(productionByCow[cow]));
                cowsByProduction[productionByCow[cow]]--;
                productionByCow[cow] += change;
                production.insert(productionByCow[cow]);
                maxSoFar = productionByCow[cow];
                cowsByProduction[productionByCow[cow]]++;
                cowsAtMax = 1;
                changesToPicture++;
            }
            else if (productionByCow[cow] + change == maxSoFar) {
                //tied with top
                production.erase(production.find(productionByCow[cow]));
                cowsByProduction[productionByCow[cow]]--;
                productionByCow[cow] += change;
                production.insert(productionByCow[cow]);
                maxSoFar = productionByCow[cow];
                cowsByProduction[productionByCow[cow]]++;
                cowsAtMax++;
                changesToPicture++;
            }
            else {
                production.erase(production.find(productionByCow[cow]));
                cowsByProduction[productionByCow[cow]]--;
                productionByCow[cow] += change;
                production.insert(productionByCow[cow]);
                cowsByProduction[productionByCow[cow]]++;
            }
        }
    }

    cout << changesToPicture;



}
