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
#include<bitset>


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

long long int MOD = 1000000007;

long long int raiseMOD(long long int base, long long int m){
    long long int ans = 1;
    while(m--){
        ans *= base;
        ans %= MOD;
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n, m;
        cin >> n >> m;
        cout << raiseMOD(pow(2, n) - 1, m) << endl;
    }
    return 0;
}