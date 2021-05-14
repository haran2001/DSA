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

#define R 4
#define C 5

int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

struct Cell{
    int x;
    int y;
    int cost;
};


class myComparision{
    public:
        bool operator()(const Cell &lhs, const Cell &rhs) const{
            return (lhs.cost > rhs.cost);
        }
};


bool isSafe(int x, int y){
    return x >= 0 && x < R && y >= 0 && y < C;
}


int minCost(int cost[R][C], int m, int n){
    int dp[R][C];
    bool visited[R][C];

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            dp[i][j] = INT_MAX;
            visited[i][j] = false;
        }
    }

    priority_queue<Cell, vector<Cell>, myComparision> pq;

    dp[0][0] = cost[0][0];
    pq.push({0, 0, cost[0][0]});

    while(!pq.empty()){
        Cell cell;
        pq.pop();
        int x = cell.x; 
        int y = cell.y;

        if(visited[x][y]) continue;

        visited[x][y] = true;
        
        for(int i=0; i<8; i++){
            int next_x = x + dx[i];
            int next_y = y + dy[i];

            if(isSafe(next_x, next_y) && !visited[next_x][next_y]){
                dp[next_x][next_y] = min(dp[next_x][next_y], dp[x][y] + cost[next_x][next_y]);
                pq.push({next_x, next_y, dp[next_x][next_y]});
            }
        } 
    }
    return dp[m][n];
}



int main(){
    int cost[R][C] = {
        {1, 8, 8, 1, 5},
        {4, 1, 1, 8, 1},
        {4, 2, 8, 8, 1},
        {1, 5, 8, 8, 1}
    };

    printf(" %d ", minCost(cost, 3, 4));
    return 0;
}