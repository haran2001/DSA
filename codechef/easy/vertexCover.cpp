//https://www.geeksforgeeks.org/vertex-cover-problem-set-1-introduction-approximate-algorithm-2/#include<iostream>

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

class Graph{
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int v, int w);
    void printVertexCover();
};


Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v){
    adj[u].pb(v);
    adj[v].pb(u);
}

void Graph::printVertexCover(){
    bool* visited = new bool[V];
    for(int i=0; i<V; i++)
        visited[i] = false;
    
    list<int>::iterator it;

    for(int u=0; u<V; u++){
        if(visited[u] == false){
            for(it = adj[u].begin(); it != adj[u].end(); it++){
                int v = *it;
                if(visited[v] == false){
                    visited[v] = true;
                    visited[u] = true;
                    break;
                }
            }
        }
    }

    for(int i=0; i<V; i++)
        if(visited[i])
            cout << i << " ";
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

        Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
 
    g.printVertexCover();
    return 0;
}