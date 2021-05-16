//template for dp
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<iterator>
#include<string.h>
#include<unordered_set>
#include<algorithm>



using namespace std;

int minJumps(int arr[], int n){
    int* jumps = new int[n];
    int i, j;

    if(n == 0 || arr[0] == 0)
        return INT_MAX;

    jumps[0] = 0;
    
    for(int i=1; i<n; i++){
        jumps[i] = INT_MAX;
        for(int j=0; j<i; j++){
            if(i <= j + arr[j] && jumps[j] != INT_MAX){
                jumps[i] = min(jumps[i], jumps[j] + 1);
                break;
            }
        }
    }

    return jumps[n-1];

}


int main(){
    int arr[] = {1, 3, 6, 1, 0, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << minJumps(arr, n) << endl;
    return 0;
}