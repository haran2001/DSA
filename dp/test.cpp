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


int count(int S[], int n, int m){
    int x, y;
    int table** = new int* [n+1];

    for(int i=0; i<n+1; i++)
        table[i] = new int [m];
    
    for(int i=0; i<m; i++)
        table[0][i] = 1;

    for(int i=1; i<n+1; i++){
        for(int j=0; j<m; j++){

        }
    }
}

int main(){
    cout << "Hello world" << endl;
}