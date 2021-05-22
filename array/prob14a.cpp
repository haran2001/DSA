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

int solve(int arr[], int n, int k){
    sort(arr, arr+n);
    return arr[k-1];
}



int main(){
    int arr[] = {1, 7, 2, 4, 5,2 ,4 ,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3; 
    cout << solve(arr, n, k) << endl;
    return 0;
}