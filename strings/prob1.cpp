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

void solve(string s){
    vector<string> tmp;
    string str = "";

    for(int i=0; i<s.length(); i++){
        if(s[i] == ' '){
            tmp.push_back(str);
            str = "";
        }

        else
            str += s[i];
    }

    tmp.push_back(str);

    for(int i=tmp.size(); i>=0; i--)
        cout << tmp[i] << " ";
}


int main(){
    string s = "hello thet how are you";
    solve(s);
    return 0;
}