//find largest number with given conditions
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

void largest(int sum, int digits){
    int tot = digits;
    int i=9;
    int *number = new int[tot];

    while(digits > 0){
        if(i <= sum){
            sum -= i;
            number[tot - digits] = i;
            digits--;
        }

        else{
            i--;
        }
    }

    for(int i=0; i<tot; i++)
        cout << number[i];
}

int main(){
    largest(18, 2);
    return 0;
}