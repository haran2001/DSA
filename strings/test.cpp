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

int findMinInsertionsDP(string str, int n){
    int **table = new int* [n];
    
    for(int i=0; i<n; i++)
        table[i] = new int[n];
    
    int l, h, gap;

    memset(table, 0, sizeof(table));
    
    for(gap=1; gap<n; gap++){
        for(l=0, h=gap; h<n; l++, h++)
            table[l][h] = (str[l] == str[h])?table[l+1][h-1]:
                            (min(table[l][h-1], table[l+1][h]) + 1);
    
    }

    return table[0][n-1];
}


int main(){
    string str = "geeks";
    int n = str.length();
    cout << findMinInsertionsDP(str, n) << endl;
    return 0;
}