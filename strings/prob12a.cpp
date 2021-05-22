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


int check(string str1, string str2){
    int n = str1.length();
    int m = str2.length();
    n = min(n, m);

    int count = 0;

    for(int i=0; i<n; i++){
        if(str1[i] == str2[i])
            count++;
        else
            break;
    }

    return count;
}


void solve(vector<string> v, int n){
    vector<string>::iterator it;

    int res = INT_MAX;

    for(it = v.begin(); it != v.end() - 1; it++){
        res = min(res, check(*it, *(it + 1)));
    }

    string s = v[0];
    for(int i=0; i<res; i++)
        cout << s[i];
}

int main(){
    vector<string> v{"geeksforgeeks", "geeks", "geek", "geezer"};
    int n = v.size();

    solve(v, n);
    return 0;
}