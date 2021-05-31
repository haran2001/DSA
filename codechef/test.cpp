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



int solve(int arr[], int n, int k){
    int sum1 = 0, sum2 = 0;
    int x = 2 * k + 1;
    
    sort(arr, arr+n, greater<int>());

    for(int i=0; i<x; i++)
        sum1 += arr[i];
    
    arr[x-2] += arr[x-1];

    for(int i=0; i<x-1; i += 2)
        sum2 += arr[i];

    return (max(sum2, sum1 - sum2));
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k, i=0;
        scanf("%d %d", &n, &k);
        int * arr = new int[n];
        
        while(i<n){
            cin >> arr[i];
            i++;
        }

        cout << solve(arr, n, k) << endl;
    }
    return 0;
}