//template for backtracking
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
#include<set>
#include<queue>
#include<numeric>
#include<list>
#include<iterator>

#define all(v) v.begin(), v.end()
#define sz(v) (int)(v.size())
#define rz(v, n) v.resize((n) + 1);
#define pb push_back
#define fi first
#define se second
#define vi vector <int>
#define pi pair <int, int>
#define vpi vector <pi>
#define vvi vector <vi>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
const int inf = 2147483647;
const int N = 2e5 + 1;
#define ll long long int

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

void solve(ll arr[], ll k[], ll n1, ll n2){
    ll count=0, i=0, p1 = -inf, p2 = inf;
    ll * paths = new ll[n1];

    FOR(i, 0, n1-1)
        paths[i] = inf;

    for(ll i=0; i<n1; i++){
        if(arr[i] != 0)
            paths[i] = 0;
    }

    for(ll i=0; i<n1; i++){
        if(arr[i] == 1)
            p1 = i;
        if(arr[i] == 0 && p1 != -inf)
            paths[i] = min(paths[i], i - p1);
    }

    for(ll i=n1-1; i>=0; i--){
        if(arr[i] == 2)
            p2 = i;
        if(arr[i] == 0 && p2 != inf)
            paths[i] = min(paths[i], p2 - i);
    }


    FOR(i, 0, n2-1){
        if(paths[k[i] - 1] == inf)
            cout << -1 << " ";
        else
            cout << paths[k[i] - 1] << " ";
    }

    cout << endl;
}



int  main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    ll t;
    cin >> t;
    while(t--){
        ll n1, n2;

        cin >> n1 >> n2;

        ll * arr1 = new ll[n1];
        ll * arr2 = new ll[n2];

        FOR(i, 0, n1-1)
            cin >> arr1[i]; 
        
        FOR(i, 0, n2-1)
            cin >> arr2[i]; 

        solve(arr1, arr2, n1, n2);
    }
    return 0;
}