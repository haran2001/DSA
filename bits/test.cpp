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
#include<bitset>


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

int count_bits(int n){
    int count = 0;
    while(n > 0){
        if(n & 1)
            count++;
        n /= 2;
    }
    return count;
}

int solve(int n){
    int count =0;

    while(n--){
        count += (count_bits(n));
    }
    return count;
}

int main(){
    cout << solve(3) << endl;
    return 0;
}