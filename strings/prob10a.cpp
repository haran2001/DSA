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
#include<set>

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

int solve(char str[], int l, int h){
    if(l > h) return INT_MAX;
    if(l == h) return 0;
    if(l == h-1) return (str[l] == str[h])?0:1;
    return (str[l] == str[h])?solve(str, l+1, h-1):
    min(solve(str, l+1, h), solve(str, l, h-1)) + 1;
}


int main(){
    char str[] = "geeks";
    cout << solve(str, 0, strlen(str)-1);
    return 0;
}