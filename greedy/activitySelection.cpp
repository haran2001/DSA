#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<iterator>
#include<string.h>
#include<unordered_set>
#include<algorithm>

using namespace std;

int min3(int a, int b, int c){
    return min(a, min(b, c));
}

void printMaxActivities(int s[], int f[], int n){
    int i, j;
    i=0;

    cout << " " << i;
    for(int j=1; j<n; j++){
        if(s[j] >= f[i]){
            cout << " " << j;
            i=j;
        }
    }
}

int main(){
    int s[] =  {1, 3, 0, 5, 8, 5};
    int f[] =  {2, 4, 6, 7, 9, 9};
    int n = sizeof(s)/sizeof(s[0]);
    printMaxActivities(s, f, n);
    return 0;
}