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

void solve(int arr[], int n, int k){
    for(int i=0; i<n; i += k){
        int left = i;

        int right = min(i+k-1, n-1);
        while(left < right){
            swap(arr[left++], arr[right--]);
        }
    }

    for(int i=0; i<n; i++)
        cout << arr[i] << " ";

}


int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k=3;

    solve(arr, n, k);
}