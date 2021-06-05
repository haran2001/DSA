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

#define NUM_BITS 32

class gfg{
    public:
        int leftRotate(int n, int d){
            return (n << d) | (n >> (NUM_BITS - d));
        }

        int rightRotate(int n, int d){
            return (n >> d) | (n << (NUM_BITS - d));
        }
};


int main(){
    gfg g;
    int n = 16, d = 2;
    cout << g.leftRotate(16, 2) << endl;
    cout << g.rightRotate(16, 2) << endl;
    return 0;
}