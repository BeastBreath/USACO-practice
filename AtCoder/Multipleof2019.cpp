#include<string>
#include<iostream>
#include<cstdio>

using namespace std;

int main () {

    int S;
    cin >> S;
    
    /*int a = 10;
    char *intStr = itoa(a);
    string str = string(intStr);*/

    int valid = 0;
    int s = 1;
    s = S/10;
    s = s % 2019;
    
    

    cout << valid << endl;

}
/*
ABC,DEF
200,000
2019

S/10

AB,CDE
*10 + F
ABC,DEF

% 100,000
S/10
B,CDE
*10 + F
BC,DEF

%10,000
C,DEF
*/