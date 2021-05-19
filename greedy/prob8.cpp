//Minimize the sum of product of two arrays with permutations allowed
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


using namespace std;

int min3(int a, int b, int c){
    return min(a, min(b, c));
}

int max3(int a, int b, int c){
    return max(a, max(b, c));
}

bool comparator1(int a, int b){
    return a > b;
}

bool comparator2(int a, int b){
    return a < b;
}

void solve(int arr1[], int arr2[], int n){
    sort(arr1, arr1+n, comparator1);
    sort(arr2, arr2+n, comparator2);

    int sum = 0;

    for(int i=0; i<n; i++){
        sum += (arr1[i] * arr2[i]);
    }

    cout << sum << endl;
}

int main(){
    int arr1[] = {3, 1, 1};
    int arr2[] = {6, 5, 4};

    int n = sizeof(arr1) / sizeof(arr1[0]);
    solve(arr1, arr2, n);
    return 0;
}