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
    int count =0;

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[j] > arr[i])
                count++;
        }
    }

    return count;
}


int main(){
    int arr[] = {8, 4, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << solve(arr, n) << endl;

    return 0;

}