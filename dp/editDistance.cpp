//template for dp
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

int editDistance(string str1, string str2, int m, int n){
    int **dp = new int* [m+1];
    
    for(int i=0; i<m; i++)
        dp[i] = new int[n+1];
    
    for(int i=0; i<m+1; i++){
        for(int j=0; j<n+1; j++){
            
            if(i == 0)
                dp[i][j] = j;
            
            else if(j == 0)
                dp[i][j] = i;

            else if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];

            else
                dp[i][j] = 1 + min3(dp[i-1][j],
                dp[i][j-1],
                dp[i-1][j-1]);
        }
    }

    return dp[m][n];
}


int main(){
    string str1 = "hello world";
    string str2 = "heo world";

    int m = str1.length();
    int n = str2.length();


    cout << editDistance(str1, str2, m, n) << endl;

    return 0;
}