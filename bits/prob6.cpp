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

bool isPowerof2(int n){
    int count = 0;
    while(n > 0){
        count += (n & 1);
        n /= 2;
    }

    return count == 1;
}


int main(){
    cout << isPowerof2(3) << endl; 
    return 0;
}