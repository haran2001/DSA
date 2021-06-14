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
#include<assert.h>


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

const int N= 5e5+3;
map<ll, int> m;
vector<int> a;
multiset<int> s;
vector<int> v[N];
ll k;
int n;
int msb;

void init(){
    FOR(i, 0, n)
        v[i].clear();
    a.clear();
    m.clear();
}

void findmsb(){
    FOR(i, 0, 63)
        if(k&(1LL<<i))
            msb = i;
}

bool dfs(int src, int par){
    m[a[src-1]]++;
    bool ok = 0;
    for(auto i: v[src]){
        if(i ^ par){
            ok | dfs(i, src);
        }
    }

    if(v[src].size() == 1 && v[src][0] == par){
        assert(m.size() > 0);
        auto big = m.rbegin();
        auto small = m.begin();

        if(big->first > msb && (big->second)%2 == 0)
            ok  |= 1;
        if(big->first == msb && (big->second)%2 == 1)
            ok  |= 1;
        if(small->first > msb && m.size() != 1)
            ok  |= 1;
        if(small->first == msb)
            ok |= 1;
    }

    m[a[src-1]]--;
    if(m.find(a[src-1]) != m.end() && m[a[src-1]] == 0)
        m.erase(a[src-1]);
    return ok;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        init();

        vector<int> a(n);

        FOR(i, 0, n-2){
            int x, y;
            cin >> x >> y;
            assert(x > 0 && x <= n && y > 0 && y <= n);
            v[x].pb(y);
            v[y].pb(x);
        }        

        FOR(i, 0, n-1){
            cin >> a[i];
            a[i]--;

            assert(a[i] < 64);
            assert(a[i] >= 0);
        }
        
        findmsb();
        bool ok = dfs(1, -1);
        cout << (ok?"YES":"NO")<<endl;
    }

    return 0;
}