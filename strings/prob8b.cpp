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


char *solve(char str[], int n){
    unordered_set<char> s(str, str+n-1);

    int i=s.size()-1;
    str[i+1] = '\0';

    for(auto x:s)
        str[i--] = x;

    return str;
}


int main(){
    char str[] = "helllooo";
    int n = sizeof(str) / sizeof(str[0]);
    cout << solve(str, n) << endl; 
    return 0;
}