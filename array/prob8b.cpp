//template for arrays
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
// #include<map>
// #include<iterator>
// #include<string.h>
// #include<unordered_set>
// #include<unordered_map>
// #include<algorithm>
// #include<vector>
// #include<cmath>


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

int _mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid, int right);    

int mergeSort(int arr[], int array_size){
    int *temp = new int[array_size];

    return _mergeSort(arr, temp, 0, array_size-1);
}


int _mergeSort(int arr[], int temp[], int left, int right){
    int i, j, inv_count=0;

    if(right > left){
        int mid = (right + left) / 2;
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid+1, right);

        inv_count += merge(arr, temp, left, mid+1, right);
    }

    return inv_count;
}

int merge(int arr[], int temp[], int left, int mid, int right){
    int i = left, j = mid, k = left;
    int inv_count = 0;
    while((i <= mid-1) && (j<=right)){
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else{
            temp[k++] = arr[j++];
            inv_count += (mid - i);
        }
    }

    while(i <= mid+1)
        temp[k++] = arr[i++];

    while(j <= right)
        temp[k++] = arr[j++];

    for(int i=left; i<=right; i++)
        arr[i] = temp[i];

    return inv_count;
}

int main(){
    int arr[] = { 1, 20, 6, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = mergeSort(arr, n);
    cout << " Number of inversions are " << ans;
    return 0;
}