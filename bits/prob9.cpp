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

unsigned int swapBits(unsigned int x){
    unsigned int even_bits = x & 0xAAAAAAAA;
    unsigned int odd_bits = x & 0x55555555;

    even_bits >>= 1; 
    odd_bits <<= 1; 

    return (even_bits | odd_bits);
}


int main(){
    unsigned int x = 23;
    cout << swapBits(23) << endl;
    return 0;
}