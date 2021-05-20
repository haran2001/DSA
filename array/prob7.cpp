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


int count(int x, int Y[], int n, int NoOfY[]){
    if(x == 0)
        return 0;
    
    if(x == 1)
        return NoOfY[0];
    
    int *idx = upper_bound(Y, Y+n, x);
    int ans = (Y+n) - idx;

    ans += (NoOfY[0] + NoOfY[1]);

    if(x == 2)
        ans -= (NoOfY[3] + NoOfY[4]);

    if(x == 3)
        ans += NoOfY[2];
    
    return ans;
}


int countPairs(int X[], int Y[], int m, int n){
    int NoOfY[5] = {0};
    
    for(int i=0; i<n; i++)
        if(Y[i] < 5)
            NoOfY[Y[i]]++;
    
    sort(Y, Y+n);

    int total_pairs = 0;

    for(int i=0; i<n; i++)
        total_pairs += count(X[i], Y, n, NoOfY);
    
    return total_pairs;

}


int main(){
    int X[] = {2, 1, 6};
    int Y[] = {1, 5};
    int m = sizeof(X) / sizeof(X[0]);
    int n = sizeof(Y) / sizeof(Y[0]);

    cout << countPairs(X, Y, m, n) << endl;
    return 0;
}