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

bool solve(string str1, string str2){
    int n1 = str1.length();
    int n2 = str2.length();
    if(n1 != n2)
        return false;
    
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    for(int i=0; i<n1; i++)
        if(str1[i] != str2[i])
            return false;
        
    return true;
}



int main(){
    string str1 = "hello";
    string str2 = "gta";

    cout << solve(str1, str2) << endl;
    return 0;
}