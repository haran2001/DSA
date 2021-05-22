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

int solve(string str1, string str2){
    int n = str1.length();
    int m = str2.length();
    int i, j;

    for(i=0; i<n-m; i++){
        
        for(j=0; j<m; j++)
            if(str1[i+j] != str2[j])
                break;
            
            if(j == m)
                return i;
            
    }

    return -1;
}


int main(){
    string str1 = "hello";
    string str2 = "he";

    cout << solve(str1, str2) << endl;
    return 0;
}