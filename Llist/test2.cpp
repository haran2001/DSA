//template for Llist
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
    int max = *max_element(arr, arr+n);
    int *temp = new int[max];
    temp = {0}; 

    for(int i=0; i<n; i++){
        cout << "Hello world" << endl;
        temp[arr[i]]++;
    }

    for(int i=0; i<n; i++){
        if(temp[arr[i]] == 1)
            return arr[i];
    }

    return -1;
}


int main(){
    int arr[] = {1, 1, 2, 2, 3, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = solve(arr, n);
    cout << ans << endl;
    return 0;
}