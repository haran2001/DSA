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
#include <cstring>

using namespace std;

class Graph{
    int V;
    list<int> *adj;
    
    public:
    Graph(int V);
    void addEdge(int v, int w);
};


Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}


