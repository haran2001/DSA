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

int solve(string s, int n){
    int res = 0;

    for(int i=0; i<n; i++)
        res += (res * 10 + (s[i] - 'a'));

    return res;
}



int main(){
    string s = "hello";
    int n = s.length();

    cout << solve(s, n) << endl;
    return 0;
}