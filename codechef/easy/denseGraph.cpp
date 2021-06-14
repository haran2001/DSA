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

const int inf = 1e9;
const int N = 2e5 + 1;

int t, n, m, x, y, xver, yver;
vector<vector<pair<int, bool>>> adj;

void build(int v, int start, int end){
    if(start == end){
        adj[v/2].pb({v, 0});
        adj[v/2].pb({4*n + v/2, 0});
        if(start == x) xver = v;
        if(start == y) yver = v;
    }

    else{
        adj[v/2].pb({v, 0});
        adj[4*n + v].pb({4*n + v/2, 0});

        int mid =(start + end)/2;
        build(2*v, start, mid);
        build(2*v + 1, mid+1, end);
    }
}

void segsearch(int v, int start, int end, int l, int r, int icnt, bool state){
    int mid = (start + end)/2;

    if(start >= l && end <= r){
        if(state) adj[6*n + icnt].pb({v, 1});
        else if(start == end) adj[v].pb({6*n + icnt, 1});
        else adj[4*n + v].pb({6*n + icnt, 1});
    }

    else if(end < l || start > r) return;
    else{
        segsearch(2*v, start, mid, l, r, icnt, state);
        segsearch(2*v + 1, mid + 1, end, l, r, icnt, state);
    }
}


int bfs(){
    vi d(6*n + m+ 1, inf);
    deque<int> q;
    d[xver] = 0;
    q.push_front(xver);

    while(!q.empty()){
        int v = q.front();
        q.pop_front();

        for(pi e: adj[v]){
            int u = e.fi, w = e.se;
            if(d[u] > d[v] + w){
                d[u] = d[v] + w;
                if(w) q.pb(u);
                else q.push_front(u);
            }
        }
    }

    if (d[yver] < inf) return d[yver]/2;
    else return -1;
    
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        cin >> n >> m >> x >> y;

        vi vec;

        set<int> s = {x, y};

        FOR(i, 1, m){
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            vec.pb(a), vec.pb(b), vec.pb(c), vec.pb(d);
            s.insert(a), s.insert(b), s.insert(c), s.insert(d);
        }

        map<int, int> mp;
        int cnt = 0;
        for(int i: s) mp[i] = ++cnt;
        FOR(i, 0, sz(vec) - 1) vec[i] = mp[vec[i]];
        x = mp[x], y = mp[y];
        
        n = sz(s);
        adj.clear();
        adj.resize(6*n + m + 1);

        build(1, 1, n);
        
        int i=0, icnt = 1;

        while(i < sz(vec)){
            segsearch(1, 1, n, vec[i], vec[i+1], icnt, 0);
            segsearch(1, 1, n, vec[i+2], vec[i+3], icnt, 0);
            i += 4, icnt++;
        }

        cout << bfs() << endl; 
    }
    return 0;
}