//template for backtracking
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
#include<queue>

#define N 4

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

 
void printSolution(int sol[N][N]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            cout << sol[i][j] << " ";
        cout << endl;
    }
} 


int main(){
    cout << "Hello world" << endl;
    return 0;
}