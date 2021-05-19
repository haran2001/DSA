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

int solve(int arr[], int n, int sum){
    int curr_sum=0;

    for(int i=0; i<n; i++){
        curr_sum = arr[i];
        for(int j=i+1; j<n; j++){
            if(sum == curr_sum){
                cout << i << " " << j-1 << endl;
                return 1;
            }

            if(curr_sum > sum)
                break;
            
            curr_sum += arr[j];
        }
    }

    cout << "sum not found" << endl;
    return 0;

}

int main(){
       int arr[] = { 15, 2, 4, 8, 9, 5, 10, 23 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 23;
    solve(arr, n, sum);
    return 0;
}