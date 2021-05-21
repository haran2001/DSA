//template for arrays
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<iterator>
#include<string.h>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>

using namespace std;

int min3(int a, int b, int c){
    return min(a, min(b, c));
}

int max3(int a, int b, int c){
    return max(a, max(b, c));
}

bool comparator(int a, int b){
    return a > b;
}

char * solve(char str[], int n){
    int index=0;
    sort(str, str+n-1);
    char* temp = new char[n];

    for(int i=1; i<n; i++){
        if(str[i] == str[i-1])
            continue;
        else
            temp[index++] = str[i-1];
    }

    temp[index] = '\0';
    return temp;
}


int main(){
    char str[] = "hhy";
    int n = sizeof(str) / sizeof(str[0]);

    cout << solve(str, n) << endl;
    return 0;
}