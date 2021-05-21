//template for arrays
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<iterator>
#include<string.h>
#include<unordered_set>
#include<set>
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

int main(){
    set<int> s;
    s.insert(3);
    s.insert(4);
    s.insert(1);
    s.insert(2);

    for(auto i = s.begin(); i != s.end(); i++)
        cout << *i << endl;
    return 0;
}