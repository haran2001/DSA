//template for greedy
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
    return a < b;
}

bool comparator2(int a, int b){
    return a > b;
}

void solve(int arr[], int n, int k){
    sort(arr, arr+n, comparator1);

    int sum1=0;
    int sum2=0;
    int test2 = n;

    for(int i=0; i<n; i++){
        sum1 += arr[i];
        n -= k;
    }

    int test=0;
    n = test2;
    for(int i=n-1; i>=test; i--){
        sum2 += arr[i];
        test += k;
    }

    cout << sum1 << endl;
    cout << sum2 << endl;
}

int main(){
    int arr[] = { 3, 2, 1, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
 
    solve(arr, n, k);
    return 0;
}