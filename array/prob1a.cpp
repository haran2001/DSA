//Find subarray with given sum
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

bool comparator(int a, int b){
    return a > b;
}

bool solve(int arr[], int n, int sum){
    if(sum == 0)
        return true;
    
    if(n <= 0 || sum < 0)
        return false;

    else 
        return solve(arr, n-1, sum) || solve(arr, n-1, sum - arr[n-1]);
}


int main(){
    int arr[] = {1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 4;

    // int arr[] = { 15, 2, 4, 8, 9, 5, 10, 23 };
    // int n = sizeof(arr) / sizeof(arr[0]);
    // int sum = 23;

    if(solve(arr, n, sum))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}