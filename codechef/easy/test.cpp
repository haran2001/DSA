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
#include<iomanip>



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


const int maxtk = 5e5, maxn = 1e5, maxtn = 5e5;
const string newln = "\n", space = " ";
vector<int> g[maxn + 10], nodes;
int depth[maxn + 10], parent[maxn + 10][20];
bool visit[maxn + 10], visitk[maxn + 10];
int n, q;

bool isGraph(int u, int pa){
    parent[u][0] = pa;
    if(visit[u]) return false;
    visit[u] = true;
    for(int v: g[u]){
        if(v == pa) continue;
        depth[v] = depth[u] + 1;
        if(!isGraph(v, u)) return false;
    }
    return true;
}


int lca(int u, int v){
    if(u == v) return u;
    if(depth[u] < depth[v]) swap(u, v);
    for(int i=19; i >= 0; i--)
        if(depth[u] - (1<<i) >= depth[v])
            u = parent[u][i];
    if(u == v) return u;
    for(int i = 19; i>= 0; i--)
        if(parent[u][i] != parent[v][i])
            u = parent[u][i]; v = parent[v][i];        
    return parent[u][0];
}




int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t; cin >> t;
    int tn = 0, tk = 0;

    while(t--){
        cin >> n >> q; tn += n;

        for(int i=0; i<=n; i++){
            g[i].clear();
            visit[i] = false;
        }
    }

    return 0;
}