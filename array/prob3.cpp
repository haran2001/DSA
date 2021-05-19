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

int solve(int arr[], int size){
    int max_so_far = INT_MIN, max_ending_here=0;
    
    for(int i=0; i<size; i++){
        max_ending_here += arr[i];
        if(max_so_far < max_ending_here)
            max_so_far = max_ending_here;
        
        if(max_ending_here < 0)
            max_ending_here = 0;
    }

    return max_so_far;

}


int main(){
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_sum = solve(arr, n);

    cout << max_sum << endl;
    return 0;
}