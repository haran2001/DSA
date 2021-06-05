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

int bitDifference(int m, int n){
    int t = n ^ m;
    int count = 0;

    while(t > 0){
        if(t & 1)
            count++;
        t /= 2;
    }
    return count;
}


int arraySum(int arr[], int n){
    int sum = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            sum += (bitDifference(arr[i], arr[j]));
            sum += (bitDifference(arr[j], arr[i]));
        }
    }
    return sum;
}


int main(){
    int arr[] = {1, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << arraySum(arr, n) << endl;
    return 0;
}