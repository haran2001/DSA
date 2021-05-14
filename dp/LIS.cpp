//template for dp
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<iterator>
#include<string.h>
#include<algorithm>


using namespace std;

int lis(int arr[], int n){
    int * lis = new int[n];
    lis[0] = 1;

    for(int i=0; i<n; i++){
        lis[i] = 1;
        for(int j=0; j<i; j++)
            if(arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    }

    return *max_element(lis, lis+n);
}

int main(){
    int arr[] = {1, 2, 3, 4, 6, 5, 7};
    int n = sizeof(arr)/ sizeof(arr[0]);

    cout << lis(arr, n);
}