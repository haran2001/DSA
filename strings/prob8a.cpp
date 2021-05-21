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

char* solve(char str[], int n){
    int index = 0;  
    int i=0, j=0;
    for(i=0; i<n; i++){
        for(j=0; j<i; j++)
            if(str[i] == str[j])
                break;

        if(i == j)
            str[index++] = str[i];
    }

    return str;
}



int main(){
    char str[] = "hhell";
    int n = sizeof(str) / sizeof(str[0]);

    cout << solve(str, n) << endl;
    return 0;
}