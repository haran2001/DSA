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

pair<bool, int> board[101][101];
unordered_map<int, unordered_set<int>> adj;
bool is_visited[2501];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int N, M, last_vtx;


void bfs(int i, int j, int clr){
    queue<pair<int, int>> q;
    q.push({i, j});

    while(!q.empty()){
        auto p = q.front();
        for(int d=0; d<4; d++){
            int x = p.first + dir[d][0], y = p.second + dir[d][1];
            if(x < 0 || x == N || y < 0 || y == M || board[x][y].second || board[x][y].first != board[p.first][p.second].first) continue;
            board[x][y].second = clr;
            q.push({x, y});
        }
    }
}



void get_adjlist(){
    last_vtx = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(board[i][j].second == 0)
                bfs(i, j, ++last_vtx);
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(i && board[i][j].second != board[i-1][j].second){
                adj[board[i][j].second].insert(board[i-1][j].second);
                adj[board[i-1][j].second].insert(board[i][j].second);
            }

            if(j && board[i][j].second != board[i][j-1].second){
                adj[board[i][j].second].insert(board[i][j-1].second);
                adj[board[i][j-1].second].insert(board[i][j].second);
            }
        }
    }
    
}

int radius_graph(){
    int radius = 2 * N * M;
    for(int vtx = 0; vtx <= last_vtx; vtx++){
        queue<int> q;
        int dist = 0;
        q.push(vtx);
        is_visited[vtx] = true;
        q.push(-1);

        while(q.empty()){
            int curr_vtx = q.front();
            q.pop();
            if(curr_vtx == -1){
                if(!q.empty()) {q.push(-1); ++dist;}
                else break;
            }

            for(int v : adj[curr_vtx]){
                if(is_visited[v] == false){
                    is_visited[v] = true;
                    q.push(v);
                }
            }
            radius = min(radius, dist);
        }
    }
    return radius;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        memset(board, 0, sizeof(board));
        cin>>M>>N;
        FOR(i, 0, N-1) FOR(j, 0, M-1) cin >> board[i][j].first;
        get_adjlist();
        cout << radius_graph() << "\n";
        adj.clear();
    }
    return 0;
}