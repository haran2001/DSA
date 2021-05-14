//Max Chain Length
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<iterator>


using namespace std;

struct val{
    int first;
    int second;
};

map<pair<int, int>, int> m;

int findMaxChainLength(struct val p[], int n, int prev, int pos){
    if(m.find({pos, prev}) != m.end())
        return m[{pos, prev}];

    if(pos >= n)
        return 0;
    
    if(p[pos].first <= prev)
        return findMaxChainLength(p, n, prev, pos + 1);

    else{
        int ans = max(findMaxChainLength(p, n, p[pos].second, 0) + 1, findMaxChainLength(p, n, prev, pos + 1));
        m[{pos, prev}] = ans;
        return ans;
    }
}

int maxChainLen(struct val p[], int n){
    m.clear();
    int ans = findMaxChainLength(p, n, 0, 0); 
    return ans;
}


int main(){
    int n = 5;
    struct val *p = new val[5];
    p[0].first = 5;
    p[0].second = 24;

    p[1].first = 39;
    p[1].second = 60;

    p[2].first = 15;
    p[2].second = 28;

    p[3].first = 27;
    p[3].second = 40;
 
    p[4].first = 50;
    p[4].second = 90; 

    cout << maxChainLen(p, n) << endl;
    return 0;
}