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

void solve(int arr[], int n){
    int i, j;

    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if(arr[i] <= arr[j])
                break;
        }
    if(j == n)
         cout << arr[i] << " ";
    }
}


int main(){
    int arr[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    solve(arr, n);
    return 0;
}