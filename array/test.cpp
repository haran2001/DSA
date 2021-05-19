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

int solve(int arr1[], int arr2[], int m, int n){
    int count=0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++)
            if(pow(arr1[i], arr2[j]) > pow(arr2[j], arr1[i]))
            count++;
    }

    return count;
}

int main(){
    int arr1[] = {2, 1, 6};
    int arr2[] = {1, 5};
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);

    cout << solve(arr1, arr2, m, n) << endl;
    // cout << pow(2, 3) << endl;
    return 0;
}