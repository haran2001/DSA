#include <iostream>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

class Graph{
    int V;
    list<int> *adj;
    void DFSUtil(int v, bool visited[]);

    public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int s);  

};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::DFSUtil(int v, bool visited[]){
    visited[v] = true;
    cout << v << " ";

    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); i++){
        if(!visited[*i])
            DFSUtil(*i, visited);
    }
}


void Graph::DFS(int s){
    bool *visited = new bool[V];

    for(int i=0; i<V; i++)
        visited[i] = false;

    DFSUtil(s, visited);
}

int main(){
    Graph g(5);
    g.addEdge(1, 2);
    g.addEdge(2, 5);
    g.addEdge(4, 1);
    g.addEdge(4, 3);
    g.addEdge(1, 3);


    g.DFS(1);
    return 0;
}