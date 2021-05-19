//template for greedy
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

const int MAX_CHAR = 26;

bool solve(int n, int k, string str){
    int arr[MAX_CHAR] = {0};
    int size = str.length();

    for(int i=0; i < size; i++){
        if(str[i] - 'a' >= 0)
            arr[str[i] - 'a']++;
    }

    for(int i=0; i<MAX_CHAR; i++){
        if(arr[i] > k)
            return false;
    }

    return true;

}


int main(){
    long long int n = 6, k = 3;
    string str = "aacaab";
  
    if (solve(n, k, str))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}