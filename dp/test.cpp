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

bool isSubsetSum(int set[], int n, int sum){
    int **table = new int* [n+1];
    
    for(int i=0; i<n+1; i++)
        table[i] = new int [sum+1];


    for(int i=0; i<n+1; i++)
        table[i][0] = true;
    
    for(int i=0; i<sum+1; i++)
        table[0][i] = false;

    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum + 1; j++){
            if(j < set[i-1])
                table[i][j] = table[i-1][j];
            if(j >= set[i-1])
                table[i][j] = table[i-1][j] || table[i-1][j - set[i-1]];
        }
    }

    return table[n][sum];
}


int main(){
     int set[] = {3, 34, 4, 12, 5, 2};
    int n = sizeof(set) / sizeof(set[0]);
    int sum = 9;

    cout << isSubsetSum(set, n, sum) << endl;
}