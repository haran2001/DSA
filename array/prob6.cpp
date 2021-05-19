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

int* solve(int arr[], int n){
    int* temp = new int[n];
    for(int i=0; i<n; i++){
        if(i%2 == 0)
            temp[i] = arr[n-1-i/2];
        else
            temp[i] = arr[(i-1)/2];
    }

    return temp;
}


int main(){
    int arr[] = { 1, 2, 3, 4, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    // cout << "Original Array\n";
    // for (int i = 0; i < n; i++)
        // cout << arr[i] << " ";
 
    int* temp = solve(arr, n);
 
    // cout << "\nModified Array\n";
    for (int i = 0; i < n; i++)
        cout << temp[i] << " ";
    return 0;
}