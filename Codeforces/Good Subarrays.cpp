#include<string>
#include<iostream>
#include<cstdio>
//#include <bits/stdc++.h>

using namespace std;

void selectionSort(int a[], int n) {
   int i, j, min, temp;
   for (i = 0; i < n - 1; i++) {
      min = i;
      for (j = i + 1; j < n; j++)
      if (a[j] < a[min])
      min = j;
      temp = a[i];
      a[i] = a[min];
      a[min] = temp;
   }
}


int main () {

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int num;
        cin >> num;
        int digits[n + 1];
        for (int i = 1; i <= n; i++) {
            digits[n + 1 - i] = num % 10;
            num /= 10;
        }
        int arr[n + 1];
        arr[0] = 0;
        for (int i = 1; i <= n; i++) {
            arr[i] = arr[i - 1] - 1 + digits[i];
        }
        
        //sort(arr, arr + n + 1);
        selectionSort(arr, n+1);

        int count = 1;
        int total = 0;
        for (int i = 1; i <= n; i++) {
            if (arr[i] == arr[i - 1]) {
                count++;
            }
            else {
                total += count * (count - 1) / 2;
                count = 1;
            }
        }
        total += count * (count - 1) / 2;
        count = 0;
        cout << total << endl;


    }

}