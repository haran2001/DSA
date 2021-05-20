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

int solve(int arr[], int n){
    int sum = 0;

    for(int i=0; i<n; i++)
        sum += arr[i];

    int cum_sum =0;

    for(int i=0; i<n; i++){
        if(cum_sum == ((sum - arr[i])/2))
            return i;
        cum_sum += arr[i];
    }

    return -1;

}



int main(){
    int arr[] = { -7, 1, 5, 2, -4, 3, 0 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    cout << solve(arr, arr_size);
    return 0;
    }