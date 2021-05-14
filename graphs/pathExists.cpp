// if path exists
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

#define N 4

bool isSafe(int i, int j, int matrix[][N]){
    if(i >= 0 && i < N && j >= 0 && j < N)
        return true;
    return false;
}


bool isPath(int matrix[][N], int i, int j, bool visited[][N]){
    if(isSafe(i, j, matrix) && matrix[i][j] != 0 && !visited[i][j]){
        visited[i][j] = true;
        if(matrix[i][j] == 2)
            return true;
        
        bool up = isPath(matrix, i - 1, j, visited);
        if(up)
            return true;
        
        bool left = isPath(matrix, i, j-1, visited);
        if(left)
            return true;
        
        bool right = isPath(matrix, i , j + 1, visited);
        if(right)
            return true;

        bool down = isPath(matrix, i + 1, j, visited);
        if(down)
            return true;
    }

    return false;
}

void isPath(int matrix[][N]){
    bool visited[N][N];
    bool flag = false;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(matrix[i][j] == 1 && !visited[i][j])
                if(isPath(matrix, i, j, visited)){
                    flag = true;
                    break;
                }
        }
    }

    if(flag)
        cout << "YES";
    else
        cout << "NO";
}

int main(){
    int matrix[][N] = {
        {0, 3, 0, 1},
        {2, 3, 3, 3},
        {0, 3, 3, 3}
    };

    isPath(matrix);
    return 0;
}