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

int maxWater(int arr[], int n){
    int left, right, res=0;

    for(int i=1; i<n-1; i++){
        left = arr[i];
        for(int j=0; j<i; j++)
            left = max(left, arr[j]);

        right = arr[i];
        for(int j=i+1; j<n; j++)
            right = max(right, arr[j]);

        res += (min(left, right) - arr[i]);
    }

    return res;

}


int main(){
       int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
     
    cout << maxWater(arr, n);
     
    return 0; }