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

bool areDistinct(string s, int i, int j){
    vector<bool> v(26);
    for(int k=i; k<=j; k++){
        if(v[s[k] - 'a'] == true)
            return false;
        v[s[k] - 'a'] = true;
    }

    return true;
}


int findLongestDistinct(string s){
    int n =s.length();
    int res =0;

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(areDistinct(s, i, j))
                res = max(res, i-j+1);
        }
    }

    return res;

}

int main(){
    string str = "geeksforgeeks";
    cout << findLongestDistinct(str) << endl;
    return 0;
}