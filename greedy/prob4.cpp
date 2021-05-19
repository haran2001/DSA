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

int max3(int a, int b, int c){
    return max(a, max(b, c));
}

bool comparator(int a, int b){
    return a > b;
}

int maxToys(int cost[], int n, int amt){
    sort(cost, cost+n, comparator);
    int count=0;

    for(int i=0; i<n; i++){
        if(amt > 0 && cost[i] < amt){
            amt -= cost[i];
            count++;
        }
    }    

    return count;
}

int main(){
        int K = 50;
    int cost[] = { 1, 12, 5, 111, 200, 1000, 10, 9, 12, 15 };
    int N = sizeof(cost) / sizeof(cost[0]);
  
    cout << maxToys(cost, N, K) << endl;
    return 0;
}