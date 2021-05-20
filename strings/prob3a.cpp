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

//struct to track the range
struct range{
    int x;
    int y;
};


//function to check if string is a palindrome
bool isPalindrome(string s, int l, int r){
    while(l < r){
        if(s[l++] != s[r--])
            return 0;
    }
    return 1;
}

//check all continous substrings
//and keep track of the longest palindromic sub-sequence 
void solve(string s, int n){
    struct range r = {0, 0};
    int max_range = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(isPalindrome(s, j, i) && (i - j) > max_range){
                r.x = j;
                r.y = i;
            }
        }
    }

    for(int i=r.x; i<=r.y; i++)
        cout << s[i];
}

int main(){
    string str = "forgeeksskeegfor";
    solve(str, str.length());
    return 0;
}