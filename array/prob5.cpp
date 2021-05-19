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

int* solve(int arr1[], int arr2[], int m, int n){
    int *temp = new int[n+m];
    int j=0, k=0;

    for(int i=0; i<m+n; i++)
        temp[i] = (arr1[j] < arr2[k])?arr1[j++]:arr2[k++];

    return temp;
}


int main(){
    // int arr1[] = { 1, 2, 4, 5, 6 };
    // int arr2[] = { 1, 2, 4, 5, 6 };

    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};
 
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
    
    int* temp = solve(arr1, arr2, m, n);
    
    for(int i=0; i<m+n; i++)
        cout << temp[i] << " ";

    return 0;
}