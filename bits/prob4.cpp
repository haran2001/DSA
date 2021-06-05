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

int toggleRange(unsigned int n, unsigned int l, unsigned int r){
    int t = ((1 << r) - 1) ^ ((1 << (l-1)) - 1);
    return n ^ t;
}



int main(){
    int num = 50, l = 2, r= 5;
    cout << toggleRange(num, l, r)<< endl;
    return 0;
}