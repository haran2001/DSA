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
// const int N = 2e5 + 1


using namespace std;

const int OO = 1e9;
const double EPS = 1e-9;

const int MX = 1e6 + 5;
const int MOD = 1000000007;

int N, S, freq[MX], a[MX], b[MX], color[MX], par[MX], deg[MX];
vector<vector<int>> adj, F;


void dfs(int u, int p){
    par[u] = p;
    deg[u] = 0;

    for(auto &v : adj[u]){
        if(v != p){
            dfs(v, u);
            ++deg[u];
        }
    }
}

void upd(int x, int delta, int &nonZero){
    if(!freq[x])
        ++nonZero;
    freq[x] += delta;
    if(!freq[x])
        --nonZero;
}

int f(int u){
    int ret = 1 + F[u].size();
    for(auto &v : F[u])
        ret = (ret * 1LL * f(v)) % MOD;
    return ret;
}   



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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);


    int T;
    cin >> T;

    int inv = 0;

    for(int tc = 1; tc <= T; tc++){
        cin >> N >> S;
        adj.assign(N+1, vector<int>());

        for(int i=1; i <= N-1; i++){
            int u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        for(int i=1; i<=N; i++)
            cin >> a[i];

        for(int i=1; i<=N; i++)
            cin >> b[i];
        
        dfs(1, 0);

        queue<int> leaves;

        for(int i=1; i<= N; i++){
            if(!deg[i])
                leaves.push(i);
        }

        for(int i=1; i<=N; i++){
            color[i] = -1;
        }

        int nonZero = 0;

        bool invalid = false;

        while(!leaves.empty()){
            int cur = leaves.front();
            leaves.pop();

            int id = cur;
            bool good = false;

            while(true){
                color[cur] = id;

                upd(a[cur], 1, nonZero);
                upd(b[cur], -1, nonZero);

                --deg[par[cur]];

                if(!nonZero){
                    good = true;
                    if(color[par[cur]] == -1 && !deg[par[cur]])
                        leaves.push(par[cur]);
                    else
                        break;
                }

                if(color[par[cur]] == -1)
                    cur = par[cur];
                else
                    break;
            }

            if(!good){
                invalid = true;
                break;
            }
        }        

        inv += invalid;

        if(invalid)
            cout << "0\n";
        else{
            if(S == 1)
                cout << "1\n";
            else{

                F.assign(N+1, vector<int>());
                vector<int> roots;
                for(int i=1; i <= N; i++){
                    if(color[i] != color[par[i]]){
                        if(i > 1 && color[par[i]] == par[i])
                            F[color[par[i]]].pb(color[i]);
                        else
                            roots.pb(color[i]);
                    }
                }

                int ans = 1;

                for(auto &root : roots)
                    ans = (ans * 1LL * f(root)) % MOD;
                cout << ans << '\n';
            }
        }





        for(int i=1; i <= N; i++){
            freq[a[i]] = freq[b[i]] = 0;
        }

    }

    return 0;
}