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

#define CHARS 256

int min3(int a, int b, int c){
    return min(a, min(b, c));
}

int max3(int a, int b, int c){
    return max(a, max(b, c));
}

bool comparator(int a, int b){
    return a > b;
}

int findLongest(string s, int n){
    vector<int> lastIndex(CHARS, -1);
    int i=0, res=0;

    for(int j=0; j<n; j++){
        i = max(i, lastIndex[s[j]] + 1);
        res = max(res, j-i+1);
        lastIndex[s[j]] = j;
    }

    return res;
}


int main(){
    string str = "geeksforgeeks";
    int n = str.length();
    cout << findLongest(str, n) << endl;
    return 0;
}