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


int sum_bit_diff(vector<int> a){
    int n = a.size();;
    int ans = 0;
    
    for(int i=0; i<n; i++){
        int count = 0;
        for(int j=0; j<i; j++){
            int x = a[i] | a[j];
            int y = a[i] & a[j];

            // int x = a[i];
            // int y = a[j];

            bitset<32> b1(x);
            bitset<32> b2(y);

            int r1 = b1.count();
            int r2 = b2.count();

            count = abs(r1 - r2);

            ans += (2 * count);
        }
    }
    return ans;
}



int main(){
    vector<int> nums{10, 5};
    int ans = sum_bit_diff(nums);
    cout << ans << endl;
    return 0;
}