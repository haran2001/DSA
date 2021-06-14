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


const int mxN = 1e5 + 5;
vector<int> tree[mxN];
int depth[mxN];

int timer;
vector<int> tin, tout;
vector<vector<int>> up;
int n, l;


void dfs(int v, int p){
    tin[v] = ++timer;
    up[v][0] = p;

    for(int i=1; i<=l; i++)
        up[v][i] = up[up[v][i-1]][i-1];
    
    for(int u: tree[v]){
        if(u != p){
            depth[u] = depth[v] + 1;
            dfs(u, v);
        }
    }

    tout[v] = ++timer;
}


bool is_ancestor(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v){
    if(is_ancestor(u, v))
        return u;

    if(is_ancestor(v, u))
        return v;

    for(int i=l; i>=0; i--){
        if(!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root){
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l+1));
    dfs(root, root);
}

void solve(){
    int q;
    cin >> n >> q;

    for(int i=0; i<n; i++){
        tree[i].clear();
        depth[i] = 0;
    }

    for(int i=0; i<n-1; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        tree[x].pb(y);
        tree[y].pb(x);
    }

    preprocess(0);
    
    while(q--){
        int k;
        cin >> k;
        
        int * a = new int[k];
        int fst_node=-1, dist=-1;

        for(int i=0; i<k; i++){
            cin >> a[i];
            a[i]--;
            if(depth[a[i]] > dist){
                dist = depth[a[i]];
                fst_node = a[i];
            }
        }

        if(k == 1)
            cout << 1 << " " << a[0] + 1 << "\n";
        else{
            dist = -1;
            int sec_node = -1;

            for(int i=0; i<k; i++){
                int temp = depth[a[i]] + depth[fst_node] - 2 * depth[lca(a[i], fst_node)];
                if(temp > dist){
                    dist = temp;
                    sec_node = a[i];
                }
            }

            if(depth[fst_node] > depth[sec_node])
                swap(fst_node, sec_node);

            int hal = dist/2;

            for(int i=l; i >= 0; i--){
                if(hal >= (1 << i)){
                    hal -= (1 << i);
                    sec_node = up[sec_node][i];
                }
            }
                if(dist%2 == 0)
                    cout << 1 << " " << sec_node +1 <<"\n";
                else
                    cout << 2 << " " << min(sec_node, up[sec_node][0]) + 1 << " " << max(sec_node, up[sec_node][0]) + 1 << endl; 
        }
        
    }
}




int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}