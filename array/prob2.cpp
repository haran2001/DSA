//count Triplets
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

int countTriplets(int arr[], int n){
    int count = 0;
    unordered_set<int> s;

    for(int i=0; i<n; i++){
            s.insert(arr[i]);
            for(int j=0; j<i; j++){
                for(int k=0; k<j; k++)
                    if(arr[i] = arr[j] + arr[k]){
                        if(s.find(arr[i]) == s.end()){
                            s.insert(arr[i]);
                            count++;
                            cout << arr[i] << " "  
                                << arr[j] << " "
                                << arr[k] << endl;
                        }
            }
        }
    }

    return count;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << countTriplets(arr, n) << endl;

    return 0; 
}