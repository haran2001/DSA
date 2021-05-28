//template for heap
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

void printMedians(double arr[], int n){
    priority_queue<double> s;
    priority_queue<double, vector<double>, greater<double>> g;
    
    double med = arr[0];
    s.push(arr[0]);
    
    for(int i=1; i<n; i++){
        double x = arr[i];
        if(s.size() > g.size()){
            if(x < med){
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else
                g.push(x);
            med = (s.top() + g.top()) / 2;
        }
        else if(s.size() == g.size()){
            if(x < med){
                s.push(x);
                med = (double)s.top();
            }
            else{
                g.push(x);
                med = (double)g.top();
            }
        }
    
        else{
            if(x > med){
                s.push(g.top());
                g.pop();
                g.push(x);
            }
            else
                s.push(x);
            med = (s.top() + g.top())/2;
        }
        cout << med << endl;
    }

}

int main(){
    double arr[] = {5, 15, 10, 20, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printMedians(arr, n);
    return 0;
}