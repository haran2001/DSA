//template for heap
//IMPORTANT
// No order of the xMove, yMove is wrong, but they will affect the running time of the algorithm drastically. 
// For example, think of the case where 8th choice of the move is the correct one and before that our code ran 7 different wrong paths.
// It’s always a good idea a have a heuristic than to try backtracking randomly. 
// Like, in this case, we know the next step would probably be in south or east direction, 
// then checking the paths which leads their first is a better strategy.


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

#define N 8

void printSolution(int sol[N][N]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            cout << sol[i][j] << " ";
        cout << endl;
    }
}

int isSafe(int x, int y, int sol[][N]){
    return (x >= 0 && x < N && y >= 0 && y< N && sol[x][y] == -1);
}

int solveKTUtil(int x, int y, int movei, int sol[][N], int xMove[], int yMove[]){
    if(movei == N*N)
        return 1;
    
    int next_x, next_y;

    // cout << "hello world" << endl;
    for(int i=0; i<N; i++){
        next_x = x + xMove[i];
        next_y = y + yMove[i];

        if(isSafe(next_x, next_y, sol) == 1){
            sol[next_x][next_y] = movei;
            if(solveKTUtil(next_x, next_y, movei + 1, sol, xMove, yMove) == 1)
                return 1;
            else
                sol[next_x][next_y] = -1;
        }
    }

    return 0;
}


void solveKT(){
    int sol[N][N];

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            sol[i][j] = -1;

    // int xMove[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
    // int yMove[] = { 1, -1, 1, -1, 2, -2, 2, -2 };
    int xMove[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int yMove[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    sol[0][0] = 0;

    if(solveKTUtil(0, 0, 1, sol, xMove, yMove) == 0)
        cout << "Not possible" << endl;
    else
        printSolution(sol);
}


int main(){
    solveKT();
    return 0;
}