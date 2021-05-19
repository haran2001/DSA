//template for greedy
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<iterator>
#include<string.h>
#include<unordered_set>
#include<algorithm>
#include<vector>


using namespace std;

int min3(int a, int b, int c){
    return min(a, min(b, c));
}

int minCoins(int a[], int n, int k){
    int minVal = *min_element(a, a+n);

    int cnt = 0;

    for(int i=0; i<n; i++){
        int diff = a[i] - minVal;
        if(diff > k)
            cnt += (diff - k);
    }

    return cnt;
}



int main(){
    int a[] = { 1, 5, 1, 2, 5, 1 };
    int n = sizeof(a) / sizeof(a[0]);
    int k = 3;
 
    cout << minCoins(a, n, k);
 
    return 0;
}