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
const int inf = 1e9;
const int N = 2e5 + 1;


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

#define ll long long int
#define pb push_back

int ct[100001];
int cnt[100001][26];

int main(){
    int t = 1;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        ll len = s.size();
        vector<ll> div;

        for(int i=1; i*i < len; i++){
            if(len % i == 0){
                div.pb(i);
                if(i*i != len){
                    div.pb(len / i);
                }
            }
        }
        ll ans = INT_MAX;
        for(auto x: div){
            if(x*n - x + 1 < k) continue;
            int m = len / x;
            for(int i=0; i<m; i++){
                ct[i] = 0;
                for(int j=0; j<26; j++){
                    cnt[i][j] = 0;
                }
            }

            for(int i=0; s[i]; i++){
                cnt[i%m][(s[i] - 'a')]++;
                ct[i%m] = max(ct[i%m], cnt[i%m][(s[i] - 'a')]);
            }

            ll count = 0;
            for(int i=0; i<m; i++){
                count += (x - ct[i]);
            }

            ans = min(ans, count);
        }
        cout << ans << "\n";
    }
    return 0;
}