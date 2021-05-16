//template for dp
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<iterator>
#include<string.h>
#include<unordered_set>
#include<algorithm>

using namespace std;

int min3(int a, int b, int c){
    return min(a, min(b, c));
}

int count(int S[], int m, int n){
    int x, y;
    int **table = new  int* [n+1];
    
    for(int i=0; i<n+1; i++)
        table[i] = new int [m];
    
    for(int i=0; i<m; i++)
        table[0][i] = 1;
    
    for(int i=1; i<n+1; i++){
        for(int j=0; j<m; j++){
            x = (i - S[j] >= 0) ? table[i - S[j]][j] : 0;
            y = (j>=1) ? table[i][j-1] : 0;
            table[i][j] = x + y;
        }
    }

    return table[n][m-1];
}


int main(){
    int arr[] = {1, 2, 3};
    int m = sizeof(arr) / sizeof(arr[0]);
    int  n = 4;
    cout << count(arr, m, n) << endl;
    return 0;
}